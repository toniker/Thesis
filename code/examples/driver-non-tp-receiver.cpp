void CAN::Driver::mcan1RxFifo1Callback(uint8_t numberOfMessages, uintptr_t context) {
    uint32_t status = MCAN1_ErrorGet() & MCAN_PSR_LEC_Msk;
    bool isStatusOk = (status == MCAN_ERROR_NONE) || (status == MCAN_ERROR_LEC_NO_CHANGE);
    auto appState = static_cast<AppStates>(context);

    if (not(isStatusOk && appState == Receive)) {
        return;
    }

    for (size_t messageNumber = 0; messageNumber < numberOfMessages; messageNumber++) {
        memset(&rxFifo1, 0x0, MCAN1_RX_FIFO0_ELEMENT_SIZE);
        if (MCAN1_MessageReceiveFifo(MCAN_RX_FIFO_1, 1, &rxFifo1)) {
            logMessage(rxFifo1, Redundant);
            CAN::Application::parseMessage(getFrame(rxFifo1));
        }
    }
}