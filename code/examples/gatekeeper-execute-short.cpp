CAN::Frame message = {};
while (true) {
    xQueueReceive(outgoingQueue, &message, portMAX_DELAY);

    CAN::Driver::send(message);
}
