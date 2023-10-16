inline void send(const CAN::Frame &message, bool isISR = false) {
    BaseType_t status;

    if (isISR) {
        BaseType_t taskShouldYield = pdFALSE;

        status = xQueueSendToBackFromISR(outgoingQueue, &message, &taskShouldYield);

        if (taskShouldYield) {
            taskYIELD();
        }
    } else {
        status = xQueueSendToBack(outgoingQueue, &message, 0);
    }

    if (status == errQUEUE_FULL) {
        LOG_ERROR << "Tried sending CAN Message while outgoing queue is full!";
    }
}
