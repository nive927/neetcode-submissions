class Singleton {
private:
    string value;
    Singleton() {}

public:

    static Singleton *getInstance() {

        static Singleton instance;    
        return &instance; // MUG

    }

    string getValue() {
        return value;
    }

    void setValue(string &value) {
        this->value = value;
    }
};
