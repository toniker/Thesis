template<typename T, size_t N>
void stuffIntoArray(T value, etl::array<uint8_t, N>& array) {
    auto currentPosition = array.size();
    for (auto i = sizeof(T); i > 0;) {
        array[currentPosition](value >> (--i * 8));
        currentPosition++;
    }
}