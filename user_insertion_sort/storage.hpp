namespace Storage
{
    const short int MAX_COUNT = 128;
    const short int DATA_LENGTH = 4;
    short int count;
    int * dataStore;

    void setup(){
        dataStore = new int[MAX_COUNT];
        count = 0;
    }

    void empty(){
        count = 0;
    }

    bool isFull(){
        return count == MAX_COUNT;
    }

    void append(int newElement){
        if (count < DATA_LENGTH){
            *(dataStore + count++ * DATA_LENGTH) = newElement;
        }
    }

    // struct PseudoArray
    // {
    //     unsigned short int memberSize;
    //     unsigned short int count;
    //     int * data;
    // };
    // struct PseudoArray dataPool;
}
