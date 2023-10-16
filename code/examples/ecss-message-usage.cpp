// Reading data
uint32_t numberOfMessages = message.readUint32();
float temperature = message.readFloat();

// Writing data
message.appendUint32(numberOfMessages);
message.appendFloat(temperature);

// You can also use templated functions, when the type is obvious and unambiguous
message.append<int16_t>(10);
message.append(someVariable);