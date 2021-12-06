#include <stdio.h>
#include "testbench.h"
#include "Vsystem.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    auto *tb = new TESTBENCH<Vsystem>();
//    tb->opentrace("trace.vcd");

    auto &mem0 = tb->m_core->system__DOT__top__DOT__blockram__DOT__rams_0__DOT__mem;
    auto &mem1 = tb->m_core->system__DOT__top__DOT__blockram__DOT__rams_1__DOT__mem;
    auto &mem2 = tb->m_core->system__DOT__top__DOT__blockram__DOT__rams_2__DOT__mem;
    auto &mem3 = tb->m_core->system__DOT__top__DOT__blockram__DOT__rams_3__DOT__mem;

    if (argc < 2) {
        printf("???? file name \n");
        exit(1);
    }

    // Initialization Here
    FILE *fp;
    fp = fopen(argv[1], "r");
    unsigned char buffer[4];

    int counter = 0;
    while (!feof(fp)) {
        size_t a = fread(buffer, 1, 4, fp);
        uint32_t instruction = 0;
        for (int i = 3; i >= 0; i--) {
            instruction = instruction << 8 | buffer[i];
        }
        mem0[counter] = (instruction >> 0U) & 0xFF;
        mem1[counter] = (instruction >> 8U) & 0xFF;
        mem2[counter] = (instruction >> 16U) & 0xFF;
        mem3[counter] = (instruction >> 24U) & 0xFF;
        if (counter >= (0x3FFFFF >> 2)) {
            printf("RAM TOO SMALL\n");
            break;
        }
        counter++;
    }



    tb->reset();
    for (int i = 0; i < 5000000; ++i) {
        tb->tick();
        if (tb->m_core->io_leds == 0x6969) {
            printf("Ayyy at cycle %d\n", i);
            exit(0);
        } else if (tb->m_core->io_leds != 0) {
            printf("LOL [%08x] %02x%02x%02x%02x\n", 0x3fc>> 2, mem3[0x3fc >> 2], mem2[0x3fc >> 2], mem1[0x3fc >> 2], mem0[0x3fc >> 2]);
            printf("LEDS got value %04x\n", tb->m_core->io_leds);
            exit(1);
        }
    }


    tb->close();

    printf("finished \n");
    return 0;
}
