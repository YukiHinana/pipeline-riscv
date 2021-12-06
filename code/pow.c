int pow(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result = mul(result, base);
    }
    return result;
}

int mul(int a, int b) {
    int res = 0;
    for(int i = 0; i < b; i++) {
        res += a;
    }
    return res;
}

int fib(int index) {
    if (index == 0) {
        return 0;
    } else if (index == 1) {
        return 1;
    } else {
        int first = 0;
        int second = 1;
        int p = 0;
        for (int i = 2; i <= index; i++) {
            p = first + second;
            first = second;
            second = p;
        }
        return p;
    }
}


int cmain() {
    int base = 2;
    int exp = 8;
    //unsigned int result = pow(base, exp);
    //unsigned int result = mul(2, 8);
    unsigned int result = fib(5);

    volatile unsigned int *leds = (unsigned int*)(0xF0000000);

    volatile unsigned int *uart_data = (unsigned int*)(0xF0001004);
    volatile unsigned int *uart_cmd = (unsigned int*)(0xF0001001);
    
    
    // // *leds = 0xFF;
    // // *leds = 0xFF;
    
    *leds = result;
    //unsigned int data;
    for(;;){
        // *leds = *uart_cmd;
    }
}