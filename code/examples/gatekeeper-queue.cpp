class CANGatekeeperTask : public Task {

    CANGatekeeperTask() {
        /**
         * A freeRTOS queue to handle outgoing messages, to keep order in case tasks interrupt each other.
         */
        QueueHandle_t outgoingQueue;

        /**
         * The variable used to hold the queue's data structure.
         */
        static inline StaticQueue_t outgoingQueueBuffer;

        /**
         * Storage area given to freeRTOS to manage the queue items.
         */
        static inline uint8_t outgoingQueueStorageArea[CAN::FrameQueueSize * sizeof(CAN::Frame)];
        
        outgoingQueue = xQueueCreateStatic(CAN::FrameQueueSize, sizeof(CAN::Frame), outgoingQueueStorageArea,
                                        &outgoingQueueBuffer);
        vQueueAddToRegistry(outgoingQueue, "CAN Outgoing");
    }
};