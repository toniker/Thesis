void CAN::Driver::mcan1RxFifo0Callback(uint8_t numberOfMessages, uintptr_t context) {
    uint32_t status = MCAN1_ErrorGet() & MCAN_PSR_LEC_Msk;
    bool isStatusOk = (status == MCAN_ERROR_NONE) || (status == MCAN_ERROR_LEC_NO_CHANGE);
    auto appState = static_cast<AppStates>(context);

    if (not(isStatusOk && appState == Receive)) {
        return;
    }

    for (size_t messageNumber = 0; messageNumber < numberOfMessages; messageNumber++) {
        memset(&rxFifo0, 0x0, (numberOfMessages * MCAN1_RX_FIFO0_ELEMENT_SIZE));
        if (MCAN1_MessageReceiveFifo(MCAN_RX_FIFO_0, 1, &rxFifo0)) {
            if (rxFifo0.data[0] >> 6 == CAN::TPProtocol::Frame::Single) {
                TPProtocol::processSingleFrame(getFrame(rxFifo0));
                continue;
            }

            canGatekeeperTask->addToIncoming(getFrame(rxFifo0));

            if (rxFifo0.data[0] >> 6 == CAN::TPProtocol::Frame::Final) {
                CAN::TPProtocol::processMultipleFrames();
            }
        }
    }
}
