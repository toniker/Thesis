void CANGatekeeperTask::execute() {
#ifdef OBC_EQM_LCL
    LCLDefinitions::lclArray[LCLDefinitions::CAN1].enableLCL();
    LCLDefinitions::lclArray[LCLDefinitions::CAN2].enableLCL();
#endif

    PIO_PinWrite(CAN::CAN_SILENT_1, false);
    PIO_PinWrite(CAN::CAN_SILENT_2, false);

    CAN::Frame message = {};

    while (true) {
        if(xTaskGetTickCount() - lastTransmissionTime > 8000) {
            LOG_ERROR << "Resetting CAN LCLs";
            LCLDefinitions::lclArray[LCLDefinitions::CAN1].enableLCL();
            LCLDefinitions::lclArray[LCLDefinitions::CAN2].enableLCL();
            MCAN0_Initialize();
            MCAN1_Initialize();
        }
        xQueueReceive(outgoingQueue, &message, portMAX_DELAY);

        CAN::Driver::send(message);
    }
}

