class DynamicArray {
public:

    int *arr; // VERY IMPORTANT DECLARATION.
    int capacity;
    int length;

    DynamicArray(int capacity) {

        arr = new int[capacity];
        length = 0;
        this->capacity = capacity;

    }

    int get(int i) {

        // if(0 <= i && i <= length - 1) {
        //     return arr[i];
        // }

        // return -1;

        return arr[i];

    }

    void set(int i, int n) {

        arr[i] = n;

    }

    void pushback(int n) {

        if(length == capacity) {
            resize();
        }

        arr[length++] = n;

    }

    int popback() {

        int back = arr[length - 1];
        length--;
        return back;

    }

    void resize() {

        capacity *= 2;
        int *newArr = new int[capacity];
        
        for(int i=0; i<length; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;

    }

    int getSize() {

        return length;

    }

    int getCapacity() {

        return capacity;

    }
};
