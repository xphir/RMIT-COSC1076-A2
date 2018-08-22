#include "helpers.h"
#include "board.h"
#include "player.h"

int64_t __gmon_start__ = 0;

void fun_4008a0();

void _init() {
    int64_t rax1;

    rax1 = __gmon_start__;
    if (rax1) {
        fun_4008a0();
    }
    return;
}

int64_t __gmon_start__ = 0x4008a6;

void fun_4008a0() {
    goto __gmon_start__;
}

int64_t deregister_tm_clones() {
    int64_t rax1;

    rax1 = 7;
    if (!0 || (*reinterpret_cast<int32_t*>(&rax1) = 0, *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax1) + 4) = 0, 1)) {
        return rax1;
    } else {
        goto 0;
    }
}

struct s0 {
    struct s0* f0;
    void* f4;
    int32_t f8;
};

int32_t board_PlacePlayer(struct s0* rdi, struct s0* rsi) {
    struct s0* v3;
    int64_t rdx4;
    int64_t rdx5;
    int64_t rdx7;

    v3 = rsi;
    if (position.x < 0 || (position.x > 4 || position.y < 0 || position.y > 4 || (rdx4 = *reinterpret_cast<int32_t*>(&v3 + 1), !!*reinterpret_cast<struct s0**>(((rdx4 << 2) + rdx4 << 2) + reinterpret_cast<uint32_t>(rdi) + position.x * 4)) && (rdx5 = *reinterpret_cast<int32_t*>(&v3 + 1), *reinterpret_cast<struct s0**>(((rdx5 << 2) + rdx5 << 2) + reinterpret_cast<uint32_t>(rdi) + position.x * 4) != 1))))) {
        return FALSE;
    } else {
        rdx7 = *reinterpret_cast<int32_t*>(&v3 + 1);
        *reinterpret_cast<struct s0**>(((rdx7 << 2) + rdx7 << 2) + reinterpret_cast<uint32_t>(rdi) + position.x * 4) = reinterpret_cast<struct s0*>(5);
        eax6 = 1;
    }
    return eax6;
}


uint32_t fun_400850(int64_t rdi, struct s0* rsi, struct s0* rdx, struct s0* rcx);

void board_DisplayWarnings(struct s0* rdi, struct s0* rsi) {
    struct s0* v3;
    struct s0* v4;
    int32_t v5;
    int32_t v6;
    int32_t v7;
    int32_t v8;
    int32_t v9;
    int64_t rdx10;
    struct s0* rdx11;
    int64_t rax12;

    v3 = rdi;
    v4 = rsi;
    v5 = 0;
    v6 = 0;
    v7 = 0;
    v8 = *reinterpret_cast<int32_t*>(&v4) - 1;
    while (*reinterpret_cast<int32_t*>(&v4) + 1 >= v8) {
        v9 = *reinterpret_cast<int32_t*>(&v4 + 1) - 1;
        while (*reinterpret_cast<int32_t*>(&v4 + 1) + 1 >= v9) {
            if (v8 >= 0 && (v8 <= 4 && (v9 >= 0 && v9 <= 4))) {
                rdx10 = v9;
                rdx11 = reinterpret_cast<struct s0*>(((rdx10 << 2) + rdx10 << 2) + reinterpret_cast<uint32_t>(v3));
                if (reinterpret_cast<uint32_t>(*reinterpret_cast<struct s0**>(reinterpret_cast<uint32_t>(rdx11) + v8 * 4)) > 5) {
                    *reinterpret_cast<int32_t*>(&rdx11) = 0xa5;
                    *reinterpret_cast<int32_t*>(&rdx11 + 1) = 0;
                    *reinterpret_cast<int32_t*>(&rsi) = reinterpret_cast<int32_t>("board.c");
                    *reinterpret_cast<int32_t*>(&rsi + 1) = 0;
                    fun_400850("FALSE", "board.c", 0xa5, "board_DisplayWarnings");
                    goto addr_400f37_8;
                } else {
                    *reinterpret_cast<struct s0**>(&rax12) = *reinterpret_cast<struct s0**>(reinterpret_cast<uint32_t>(rdx11) + v8 * 4);
                    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax12) + 4) = 0;
                    switch (rax12) {
                        addr_400f37_8:
                    case 0:
                    case 1:
                    case 5:
                        break;
                    case 2:
                        v6 = 1;
                        break;
                    case 3:
                        v7 = 1;
                        break;
                    case 4:
                        v5 = 1;
                    }
                }
            }
            ++v9;
        }
        ++v8;
    }
    if (v7) {
        printf("You feel a breeze! ", rsi, "You feel a breeze! ", rsi);
    }
    if (v6) {
        printf("You hear flapping! ", rsi, "You hear flapping! ", rsi);
    }
    if (v5) {
        printf("You smell a wumpus!", rsi, "You smell a wumpus!", rsi);
    }
    putchar(10, rsi, rdx11, 10, rsi, rdx11);
    return;
}

void* strtok(void* rdi, struct s0* rsi, struct s0* rdx);

int32_t strtol(void* rdi, struct s0* rsi, struct s0* rdx);

void board_Load(struct s0* rdi, struct s0** rsi, struct s0* rdx);

int32_t game_CommandLoad(void* rdi, struct s0* rsi, struct s0* rdx) {
    void* rax4;
    int32_t eax5;
    void* v6;
    uint32_t eax7;
    unsigned char* v8;
    int32_t eax9;

    strtok(rdi, " ", rdx);
    rax4 = strtok(0, 0x402062, rdx);
    if (rax4) {
        eax5 = strtol(rax4, reinterpret_cast<int64_t>(__zero_stack_offset()) - 8 + 0xffffffffffffffe8, 10);
        if (rax4 == v6 || ((eax7 = *v8, !!*reinterpret_cast<signed char*>(&eax7)) || (eax5 <= 0 || eax5 > 2))) {
            eax9 = 0;
        } else {
            if (eax5 == 1) {
                board_Load(rsi, 0x6030c0, 10);
            } else {
                if (eax5 == 2) {
                    board_Load(rsi, 0x603140, 10);
                } else {
                    fun_400850("FALSE", "game.c", 75, "game_CommandLoad");
                }
            }
            eax9 = 1;
        }
    } else {
        eax9 = 0;
    }
    return eax9;
}

void printInvalidInput(void* rdi, struct s0* rsi, struct s0* rdx, struct s0* rcx) {
    puts("Invalid input. \n", rsi, rdx, rcx);
    return;
}

void player_Initialise(struct s0* rdi, struct s0* rsi) {
    *reinterpret_cast<struct s0**>(&rdi->f0) = rsi;
    rdi->f8 = 5;
    return;
}

int32_t game_CommandInit(void* rdi, struct s0* rsi, struct s0* rdx, struct s0* rcx) {
    void* rbp5;
    void* rax6;
    struct s0* rcx7;
    int32_t eax8;
    struct s0* v9;
    void* v10;
    uint32_t eax11;
    unsigned char* v12;
    int32_t eax13;
    void* rax14;
    struct s0* rcx15;
    int32_t eax16;
    void* v17;
    uint32_t eax18;
    unsigned char* v19;
    int32_t eax20;

    rbp5 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(__zero_stack_offset()) - 8);
    strtok(rdi, " ", rdx);
    rax6 = strtok(0, ",", rdx);
    if (rax6) {
        rcx7 = reinterpret_cast<struct s0*>(reinterpret_cast<int64_t>(rbp5) + 0xffffffffffffffd8);
        eax8 = strtol(rax6, rcx7, 10);
        *reinterpret_cast<int32_t*>(&v9) = eax8;
        if (rax6 == v10 || ((eax11 = *v12, !!*reinterpret_cast<signed char*>(&eax11)) || (*reinterpret_cast<int32_t*>(&v9) < 0 || *reinterpret_cast<int32_t*>(&v9) > 4))) {
            printInvalidInput(rax6, rcx7, 10, rcx7);
            eax13 = 0;
        } else {
            rax14 = strtok(0, ",", 10);
            if (rax14) {
                rcx15 = reinterpret_cast<struct s0*>(reinterpret_cast<int64_t>(rbp5) + 0xffffffffffffffd8);
                eax16 = strtol(rax14, rcx15, 10);
                *reinterpret_cast<int32_t*>(&v9 + 1) = eax16;
                if (rax14 == v17 || ((eax18 = *v19, !!*reinterpret_cast<signed char*>(&eax18)) || (*reinterpret_cast<int32_t*>(&v9 + 1) < 0 || *reinterpret_cast<int32_t*>(&v9 + 1) > 4))) {
                    printInvalidInput(rax14, rcx15, 10, rcx15);
                    eax13 = 0;
                } else {
                    eax20 = board_PlacePlayer(rsi, v9);
                    if (!eax20) {
                        puts("Unable to place player at that position. \n", v9, v9, rcx15);
                    } else {
                        player_Initialise(rdx, v9);
                    }
                    eax13 = eax20;
                }
            } else {
                printInvalidInput(0, ",", 10, rcx7);
                eax13 = 0;
            }
        }
    } else {
        printInvalidInput(0, ",", rdx, rcx);
        eax13 = 0;
    }
    return eax13;
}


struct s0* player_GetNextPosition(struct s0* rdi, uint32_t esi);

uint32_t board_FireArrow(struct s0* rdi, struct s0* rsi);

int32_t game_CommandShoot(void* rdi, struct s0* rsi, struct s0* rdx, struct s0* rcx) {
    int32_t v5;
    void* rax6;
    struct s0* rsi7;
    int32_t eax8;
    int32_t eax9;
    uint32_t v10;
    int32_t eax11;
    int32_t eax12;
    int32_t eax13;
    int32_t eax14;
    int32_t eax15;
    int32_t eax16;
    int32_t eax17;
    struct s0* rdi18;
    struct s0* rax19;
    uint32_t eax20;
    int64_t rax21;
    int64_t rax22;
    struct s0* rsi23;

    v5 = 0;
    strtok(rdi, " ", rdx);
    rax6 = strtok(0, " ", rdx);
    if (rax6) {
        *reinterpret_cast<int32_t*>(&rsi7) = reinterpret_cast<int32_t>("north");
        *reinterpret_cast<int32_t*>(&rsi7 + 1) = 0;
        eax8 = strcmp(rax6, "north", rdx);
        if (!eax8 || (*reinterpret_cast<int32_t*>(&rsi7) = reinterpret_cast<int32_t>("n"), *reinterpret_cast<int32_t*>(&rsi7 + 1) = 0, eax9 = strcmp(rax6, "n", rdx), !eax9)) {
            v10 = 0;
        } else {
            *reinterpret_cast<int32_t*>(&rsi7) = reinterpret_cast<int32_t>("south");
            *reinterpret_cast<int32_t*>(&rsi7 + 1) = 0;
            eax11 = strcmp(rax6, "south", rdx);
            if (!eax11 || (*reinterpret_cast<int32_t*>(&rsi7) = reinterpret_cast<int32_t>("s"), *reinterpret_cast<int32_t*>(&rsi7 + 1) = 0, eax12 = strcmp(rax6, "s", rdx), !eax12)) {
                v10 = 2;
            } else {
                *reinterpret_cast<int32_t*>(&rsi7) = reinterpret_cast<int32_t>("east");
                *reinterpret_cast<int32_t*>(&rsi7 + 1) = 0;
                eax13 = strcmp(rax6, "east", rdx);
                if (!eax13 || (*reinterpret_cast<int32_t*>(&rsi7) = reinterpret_cast<int32_t>("e"), *reinterpret_cast<int32_t*>(&rsi7 + 1) = 0, eax14 = strcmp(rax6, "e", rdx), !eax14)) {
                    v10 = 1;
                } else {
                    *reinterpret_cast<int32_t*>(&rsi7) = reinterpret_cast<int32_t>("west");
                    *reinterpret_cast<int32_t*>(&rsi7 + 1) = 0;
                    eax15 = strcmp(rax6, "west", rdx);
                    if (!eax15 || (*reinterpret_cast<int32_t*>(&rsi7) = reinterpret_cast<int32_t>("w"), *reinterpret_cast<int32_t*>(&rsi7 + 1) = 0, eax16 = strcmp(rax6, "w", rdx), !eax16)) {
                        v10 = 3;
                    } else {
                        printInvalidInput(rax6, "w", rdx, rcx);
                        eax17 = 0;
                        goto addr_401567_11;
                    }
                }
            }
        }
    } else {
        printInvalidInput(0, " ", rdx, rcx);
        eax17 = 0;
        goto addr_401567_11;
    }
    if (rdx->f8) {
        rdi18 = *reinterpret_cast<struct s0**>(&rdx->f0);
        rax19 = player_GetNextPosition(rdi18, v10);
        eax20 = board_FireArrow(rsi, rax19);
        if (eax20 == 1) {
            puts("You killed the Wumpus!\n", rax19, rax19, rcx);
            *reinterpret_cast<int32_t*>(&rax21) = rdx->f8;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax21) + 4) = 0;
            rdx->f8 = static_cast<int32_t>(rax21 - 1);
            v5 = 1;
        } else {
            if (eax20 < 1) {
                *reinterpret_cast<int32_t*>(&rax22) = rdx->f8;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax22) + 4) = 0;
                rdx->f8 = static_cast<int32_t>(rax22 - 1);
                *reinterpret_cast<int32_t*>(&rsi23) = rdx->f8;
                *reinterpret_cast<int32_t*>(&rsi23 + 1) = 0;
                printf("Missed. You now have %d arrows\n\n", rsi23);
            } else {
                if (eax20 != 2) {
                    fun_400850("FALSE", "game.c", 0xc9, "game_CommandShoot");
                } else {
                    puts("Unable to fire arrow in that direction. \n", rax19, rax19, rcx);
                }
            }
        }
        eax17 = v5;
    } else {
        puts("You don't have any arrows to fire.\n", rsi7, rdx, rcx);
        eax17 = 0;
    }
    addr_401567_11:
    return eax17;
}

void fun_400870(int64_t rdi);

void game_DisplayOptions(int64_t rdi, struct s0* rsi);

struct s0* stdin = reinterpret_cast<struct s0*>(0);

int32_t readInput(struct s0* rdi, int32_t esi, struct s0* rdx, ...);

int32_t game_AttemptLoadCommand(struct s0* rdi, int64_t rsi, struct s0* rdx);

int32_t game_AttemptInitCommand(struct s0* rdi, struct s0* rsi);

void game_Hunt(struct s0* rdi, struct s0* rsi);

void game_PlayGame(void* rdi, struct s0* rsi) {
    void* rbp3;
    struct s0* rdx4;
    int32_t eax5;
    int32_t eax6;

    rbp3 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(__zero_stack_offset()) - 8);
    fun_400870(0);
    game_DisplayOptions(0, rsi);
    rdx4 = stdin;
    readInput(reinterpret_cast<int64_t>(rbp3) + 0xffffffffffffff70, 2, rdx4);
    eax5 = game_AttemptLoadCommand(reinterpret_cast<int64_t>(rbp3) + 0xffffffffffffff90, 2, rdx4);
    if (eax5 && (eax6 = game_AttemptInitCommand(reinterpret_cast<int64_t>(rbp3) + 0xffffffffffffff90, reinterpret_cast<int64_t>(rbp3) + 0xffffffffffffff80), !!eax6)) {
        game_Hunt(reinterpret_cast<int64_t>(rbp3) + 0xffffffffffffff90, reinterpret_cast<int64_t>(rbp3) + 0xffffffffffffff80);
    }
    return;
}

int32_t game_AttemptInitCommand(struct s0* rdi, struct s0* rsi) {
    void* rbp3;
    struct s0* v4;
    struct s0* v5;
    struct s0* rcx6;
    int32_t eax7;
    void* rdi8;
    int32_t eax9;
    int32_t eax10;
    int32_t eax11;

    rbp3 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(__zero_stack_offset()) - 8);
    v4 = rdi;
    v5 = rsi;
    while (rcx6 = reinterpret_cast<struct s0*>(reinterpret_cast<int64_t>(rbp3) + 0xffffffffffffffc0), getInput("At this stage of the program, only two commands are acceptable: \ninit <x>,<y> \nquit \n\n", rcx6, 52), eax7 = strcmp(reinterpret_cast<int64_t>(rbp3) - 64, "quit", 52), !!eax7) {
        rdi8 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(rbp3) - 64);
        eax9 = strncmp(rdi8, "init", 4);
        if (eax9) {
            printInvalidInput(rdi8, "init", 4, rcx6);
        } else {
            eax10 = game_CommandInit(reinterpret_cast<int64_t>(rbp3) - 64, v4, v5, v4);
            if (eax10 == 1) 
                goto addr_40133a_6;
        }
    }
    eax11 = 0;
    addr_401355_9:
    return eax11;
    addr_40133a_6:
    eax11 = 1;
    goto addr_401355_9;
}

void board_Display(struct s0* rdi, struct s0* rsi, struct s0* rdx);

uint32_t game_AttemptMoveCommand(struct s0* rdi, struct s0* rsi, uint32_t edx);

void game_Hunt(struct s0* rdi, struct s0* rsi) {
    void* rbp3;
    struct s0* v4;
    struct s0* v5;
    uint32_t v6;
    struct s0* rdx7;
    struct s0* rsi8;
    struct s0* rcx9;
    int32_t eax10;
    int32_t eax11;
    uint32_t v12;
    int32_t eax13;
    int32_t eax14;
    int32_t eax15;
    int32_t eax16;
    int32_t eax17;
    int32_t eax18;
    int32_t eax19;
    void* rdi20;
    int32_t eax21;
    int32_t eax22;
    uint32_t eax23;

    rbp3 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(__zero_stack_offset()) - 8);
    v4 = rdi;
    v5 = rsi;
    v6 = 1;
    while (v6) {
        board_Display(v4, rsi, rdx7);
        rsi8 = *reinterpret_cast<struct s0**>(&v5->f0);
        board_DisplayWarnings(v4, rsi8);
        putchar(10, rsi8, v5);
        rcx9 = reinterpret_cast<struct s0*>(reinterpret_cast<int64_t>(rbp3) + 0xffffffffffffffb0);
        getInput("At this stage of the program, only three commands are acceptable: \n <direction> \n shoot <direction> \n quit \nWhere <direction> is one of: north,n,south,s,east,e,west,w\n\nPlease enter your choice: ", rcx9, 52);
        eax10 = strcmp(reinterpret_cast<int64_t>(rbp3) - 80, "north", 52);
        if (!eax10 || (eax11 = strcmp(reinterpret_cast<int64_t>(rbp3) - 80, "n", 52), !eax11)) {
            v12 = 0;
        } else {
            eax13 = strcmp(reinterpret_cast<int64_t>(rbp3) - 80, "south", 52);
            if (!eax13 || (eax14 = strcmp(reinterpret_cast<int64_t>(rbp3) - 80, "s", 52), !eax14)) {
                v12 = 2;
            } else {
                eax15 = strcmp(reinterpret_cast<int64_t>(rbp3) - 80, "east", 52);
                if (!eax15 || (eax16 = strcmp(reinterpret_cast<int64_t>(rbp3) - 80, "e", 52), !eax16)) {
                    v12 = 1;
                } else {
                    eax17 = strcmp(reinterpret_cast<int64_t>(rbp3) - 80, "west", 52);
                    if (!eax17 || (eax18 = strcmp(reinterpret_cast<int64_t>(rbp3) - 80, "w", 52), !eax18)) {
                        v12 = 3;
                    } else {
                        *reinterpret_cast<uint32_t*>(&rdx7) = 5;
                        *reinterpret_cast<int32_t*>(&rdx7 + 1) = 0;
                        eax19 = strncmp(reinterpret_cast<int64_t>(rbp3) - 80, "shoot", 5);
                        if (eax19) {
                            *reinterpret_cast<int32_t*>(&rsi) = reinterpret_cast<int32_t>("quit");
                            *reinterpret_cast<int32_t*>(&rsi + 1) = 0;
                            rdi20 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(rbp3) - 80);
                            eax21 = strcmp(rdi20, "quit", 5);
                            if (!eax21) 
                                goto addr_401870_13;
                            printInvalidInput(rdi20, "quit", 5, rcx9);
                            continue;
                        } else {
                            rdx7 = v5;
                            rsi = v4;
                            eax22 = game_CommandShoot(reinterpret_cast<int64_t>(rbp3) - 80, rsi, rdx7, v4);
                            v6 = reinterpret_cast<uint1_t>(eax22 == 0);
                            continue;
                        }
                    }
                }
            }
        }
        *reinterpret_cast<uint32_t*>(&rdx7) = v12;
        *reinterpret_cast<int32_t*>(&rdx7 + 1) = 0;
        rsi = v5;
        eax23 = game_AttemptMoveCommand(v4, rsi, *reinterpret_cast<uint32_t*>(&rdx7));
        v6 = eax23;
    }
    addr_4018a8_17:
    return;
    addr_401870_13:
    goto addr_4018a8_17;
}

int32_t readInput(struct s0* rdi, int32_t esi, struct s0* rdx, ...) {
    int64_t rsi4;
    int64_t rax5;
    void* rax6;
    struct s0* rdx7;
    uint32_t eax8;
    void* rax9;
    int32_t eax10;

    *reinterpret_cast<int32_t*>(&rsi4) = esi;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rsi4) + 4) = 0;
    rax5 = fgets(rdi, rsi4, rdx);
    if (rax5) {
        rax6 = strlen(rdi, rsi4, rdx);
        rdx7 = reinterpret_cast<struct s0*>(reinterpret_cast<int64_t>(rax6) + 0xffffffffffffffff);
        eax8 = *reinterpret_cast<unsigned char*>(reinterpret_cast<uint32_t>(rdi) + reinterpret_cast<uint32_t>(rdx7));
        if (*reinterpret_cast<signed char*>(&eax8) == 10) {
            rax9 = strlen(rdi, rsi4, rdx7);
            *reinterpret_cast<signed char*>(reinterpret_cast<uint32_t>(rdi) + reinterpret_cast<uint32_t>(reinterpret_cast<int64_t>(rax9) + 0xffffffffffffffff)) = 0;
            eax10 = 2;
        } else {
            readRestOfLine(rdi, rsi4);
            eax10 = 1;
        }
    } else {
        eax10 = 0;
    }
    return eax10;
}

int32_t fun_4008d0(struct s0* rdi);

void readRestOfLine(struct s0* rdi, int64_t rsi) {
    struct s0* rax3;
    int32_t eax4;
    int32_t eax5;
    struct s0* rax6;

    do {
        rax3 = stdin;
        eax4 = fun_4008d0(rax3);
        if (eax4 == -1 || eax4 == 10) {
            eax5 = 0;
        } else {
            eax5 = 1;
        }
    } while (eax5);
    rax6 = stdin;
    clearerr(rax6);
    return;
}

void showStudentInformation(void* rdi, struct s0* rsi) {
    printf("----------------------------------- \nName: %s \nStudent ID: %s \nEmail: %s \n----------------------------------- \n\n", "<your full name>", "----------------------------------- \nName: %s \nStudent ID: %s \nEmail: %s \n----------------------------------- \n\n", "<your full name>");
    return;
}

void board_Load(struct s0* rdi, struct s0** rsi, struct s0* rdx) {
    struct s0* v4;
    struct s0** v5;
    int32_t v6;
    int32_t v7;
    int64_t rdx8;
    int64_t rdx9;

    v4 = rdi;
    v5 = rsi;
    v6 = 0;
    while (v6 <= 4) {
        v7 = 0;
        while (v7 <= 4) {
            rdx8 = v6;
            rdx9 = v6;
            *reinterpret_cast<struct s0**>(((rdx8 << 2) + rdx8 << 2) + reinterpret_cast<uint32_t>(v4) + v7 * 4) = *reinterpret_cast<struct s0**>(((rdx9 << 2) + rdx9 << 2) + reinterpret_cast<int64_t>(v5) + v7 * 4);
            ++v7;
        }
        ++v6;
    }
    return;
}

uint32_t board_MovePlayer(struct s0* rdi, struct s0* rsi, struct s0* rdx) {
    struct s0* v4;
    struct s0* v5;
    uint32_t eax6;
    int64_t rdx7;
    int64_t rax8;
    int64_t rdx9;
    int64_t rdx10;
    int64_t rdx11;

    v4 = rsi;
    v5 = rdx;
    if (*reinterpret_cast<int32_t*>(&v5 + 1) < 0 || (*reinterpret_cast<int32_t*>(&v5 + 1) > 4 || (*reinterpret_cast<int32_t*>(&v5) < 0 || *reinterpret_cast<int32_t*>(&v5) > 4))) {
        eax6 = 3;
    } else {
        rdx7 = *reinterpret_cast<int32_t*>(&v5 + 1);
        if (reinterpret_cast<uint32_t>(*reinterpret_cast<struct s0**>(((rdx7 << 2) + rdx7 << 2) + reinterpret_cast<uint32_t>(rdi) + *reinterpret_cast<int32_t*>(&v5) * 4)) > 4) {
            eax6 = fun_400850("FALSE", "board.c", 73, "board_MovePlayer");
        } else {
            *reinterpret_cast<struct s0**>(&rax8) = *reinterpret_cast<struct s0**>(((rdx7 << 2) + rdx7 << 2) + reinterpret_cast<uint32_t>(rdi) + *reinterpret_cast<int32_t*>(&v5) * 4);
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax8) + 4) = 0;
            switch (rax8) {
            case 0:
            case 1:
                rdx9 = *reinterpret_cast<int32_t*>(&v4 + 1);
                *reinterpret_cast<struct s0**>(((rdx9 << 2) + rdx9 << 2) + reinterpret_cast<uint32_t>(rdi) + *reinterpret_cast<int32_t*>(&v4) * 4) = reinterpret_cast<struct s0*>(1);
                rdx10 = *reinterpret_cast<int32_t*>(&v5 + 1);
                *reinterpret_cast<struct s0**>(((rdx10 << 2) + rdx10 << 2) + reinterpret_cast<uint32_t>(rdi) + *reinterpret_cast<int32_t*>(&v5) * 4) = reinterpret_cast<struct s0*>(5);
                eax6 = 0;
                break;
            case 2:
                rdx11 = *reinterpret_cast<int32_t*>(&v4 + 1);
                *reinterpret_cast<struct s0**>(((rdx11 << 2) + rdx11 << 2) + reinterpret_cast<uint32_t>(rdi) + *reinterpret_cast<int32_t*>(&v4) * 4) = reinterpret_cast<struct s0*>(1);
                eax6 = 2;
                break;
            case 3:
            case 4:
                eax6 = 1;
            }
        }
    }
    return eax6;
}

uint32_t board_FireArrow(struct s0* rdi, struct s0* rsi) {
    struct s0* v3;
    uint32_t eax4;
    int64_t rdx5;

    v3 = rsi;
    if position.y < 0 || position.y > 4 || (position.x < 0 || position.x > 4))) {
        eax4 = 2;
    } else {
        rdx5 = *reinterpret_cast<int32_t*>(&v3 + 1);
        if (reinterpret_cast<uint32_t>(*reinterpret_cast<struct s0**>(((rdx5 << 2) + rdx5 << 2) + reinterpret_cast<uint32_t>(rdi) + position.x * 4)) <= 3) {
            eax4 = 0;
        } else {
            if (*reinterpret_cast<struct s0**>(((rdx5 << 2) + rdx5 << 2) + reinterpret_cast<uint32_t>(rdi) + position.x * 4) == 4) {
                eax4 = 1;
            } else {
                eax4 = fun_400850("FALSE", "board.c", 95, "board_FireArrow");
            }
        }
    }
    return eax4;
}

void board_Display(struct s0* rdi, struct s0* rsi, struct s0* rdx) {
    struct s0* v4;
    int32_t v5;
    int32_t v6;
    int32_t v7;
    int32_t v8;
    int64_t rdx9;
    int64_t rax10;
    int32_t v11;

    v4 = rdi;
    printf("   ", rsi);
    v5 = 0;
    while (v5 <= 4) {
        *reinterpret_cast<int32_t*>(&rsi) = v5;
        *reinterpret_cast<int32_t*>(&rsi + 1) = 0;
        printf("%d  ", rsi);
        ++v5;
    }
    putchar(10, rsi, rdx);
    v6 = 0;
    while (v6 <= 4) {
        printf("  -", rsi, "  -", rsi);
        v7 = 0;
        while (v7 <= 4) {
            printf("---", rsi, "---", rsi);
            ++v7;
        }
        *reinterpret_cast<int32_t*>(&rsi) = v6;
        *reinterpret_cast<int32_t*>(&rsi + 1) = 0;
        printf("\n%d ", rsi, "\n%d ", rsi);
        v8 = 0;
        while (v8 <= 4) {
            putchar(0x7c, rsi, rdx, 0x7c, rsi, rdx);
            rdx9 = v6;
            rdx = reinterpret_cast<struct s0*>(((rdx9 << 2) + rdx9 << 2) + reinterpret_cast<uint32_t>(v4));
            if (reinterpret_cast<uint32_t>(*reinterpret_cast<struct s0**>(reinterpret_cast<uint32_t>(rdx) + v8 * 4)) > 5) {
                *reinterpret_cast<int32_t*>(&rdx) = 0x83;
                *reinterpret_cast<int32_t*>(&rdx + 1) = 0;
                *reinterpret_cast<int32_t*>(&rsi) = reinterpret_cast<int32_t>("board.c");
                *reinterpret_cast<int32_t*>(&rsi + 1) = 0;
                fun_400850("FALSE", "board.c", 0x83, "board_Display");
            } else {
                *reinterpret_cast<struct s0**>(&rax10) = *reinterpret_cast<struct s0**>(reinterpret_cast<uint32_t>(rdx) + v8 * 4);
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax10) + 4) = 0;
                switch (rax10) {
                case 0:
                case 2:
                case 3:
                case 4:
                    printf("  ", rsi, "  ", rsi);
                    break;
                case 1:
                    printf("**", rsi, "**", rsi);
                    break;
                case 5:
                    printf("##", rsi, "##", rsi);
                }
            }
            ++v8;
        }
        puts("|", rsi, rdx, "board_Display");
        ++v6;
    }
    printf("  -", rsi, "  -", rsi);
    v11 = 0;
    while (v11 <= 4) {
        printf("---", rsi, "---", rsi);
        ++v11;
    }
    putchar(10, rsi, rdx, 10, rsi, rdx);
    return;
}

int64_t __assert_fail = 0x400856;

uint32_t fun_400850(int64_t rdi, struct s0* rsi, struct s0* rdx, struct s0* rcx) {
    goto __assert_fail;
}

void game_DisplayOptions(int64_t rdi, struct s0* rsi) {
    printf("You can use the following commands to play the game: \n\nload <g> \n g: number of the game board to load (either 1 or 2)\ninit <x>,<y>\n x: horizontal position of the player on the board (between 0 & 4) \n y: vertical position of the player on the board (between 0 & 4) \nnorth (or n) \nsouth (or s) \neast (or e) \nwest (or w) \nquit \n\nPress enter to continue... ", rsi);
    return;
}



int64_t stdout = 0;

void setbuf(int64_t rdi, int64_t rsi);

int64_t stderr = 0;

void enableWindowsCompatibility() {
    int64_t rax1;
    int64_t rax2;

    rax1 = stdout;
    setbuf(rax1, 0);
    rax2 = stderr;
    setbuf(rax2, 0);
    return;
}

struct s0* player_GetNextPosition(struct s0* rdi, uint32_t esi) {
    struct s0* v3;

    v3 = rdi;
    if (esi == 1) {
        position.x = position.x + 1;
    } else {
        if (esi < 1) {
            *reinterpret_cast<int32_t*>(&v3 + 1) = *reinterpret_cast<int32_t*>(&v3 + 1) - 1;
        } else {
            if (esi == 2) {
                *reinterpret_cast<int32_t*>(&v3 + 1) = *reinterpret_cast<int32_t*>(&v3 + 1) + 1;
            } else {
                if (esi == 3) {
                    position.x = position.x - 1;
                } else {
                    fun_400850("FALSE", "player.c", 29, "player_GetNextPosition");
                }
            }
        }
    }
    return v3;
}

void* fun_4008f0(struct s0* rdi, struct s0* rsi, ...);

uint32_t game_AttemptMoveCommand(struct s0* rdi, struct s0* rsi, uint32_t edx) {
    struct s0* v4;
    struct s0* v5;
    uint32_t v6;
    struct s0* rdi7;
    struct s0* rax8;
    struct s0* v9;
    struct s0* rsi10;
    struct s0* rdi11;
    uint32_t eax12;
    uint32_t v13;
    struct s0* v14;
    void* eax15;
    uint32_t edx16;
    struct s0* v17;
    void* eax18;
    int32_t edx19;
    int32_t eax20;
    uint32_t eax21;

    v4 = rdi;
    v5 = rsi;
    v6 = edx;
    do {
        rdi7 = *reinterpret_cast<struct s0**>(&v5->f0);
        rax8 = player_GetNextPosition(rdi7, v6);
        v9 = rax8;
        rsi10 = *reinterpret_cast<struct s0**>(&v5->f0);
        rdi11 = v4;
        eax12 = board_MovePlayer(rdi11, rsi10, v9);
        v13 = eax12;
        if (v13 == 1) {
            v14 = reinterpret_cast<struct s0*>("Player killed!");
        } else {
            if (v13 < 1) {
                v14 = reinterpret_cast<struct s0*>("Player moved.");
                *reinterpret_cast<struct s0**>(&v5->f0) = v9;
                v5->f4 = *reinterpret_cast<void**>(&v9 + 1);
            } else {
                if (v13 == 2) {
                    v14 = reinterpret_cast<struct s0*>("Bat cell!");
                    do {
                        eax15 = fun_4008f0(rdi11, rsi10, rdi11, rsi10);
                        edx16 = (__intrinsic() >> 1) - reinterpret_cast<uint32_t>(reinterpret_cast<int32_t>(eax15) >> 31);
                        v17 = reinterpret_cast<struct s0*>(reinterpret_cast<int32_t>(eax15) - ((edx16 << 2) + edx16));
                        eax18 = fun_4008f0(rdi11, rsi10);
                        edx19 = (__intrinsic() >> 1) - (reinterpret_cast<int32_t>(eax18) >> 31);
                        *reinterpret_cast<void**>(&v17 + 1) = reinterpret_cast<void*>(reinterpret_cast<int32_t>(eax18) - ((edx19 << 2) + edx19));
                        rsi10 = v17;
                        rdi11 = v4;
                        eax20 = board_PlacePlayer(rdi11, rsi10);
                    } while (!eax20);
                    *reinterpret_cast<struct s0**>(&v5->f0) = v17;
                    v5->f4 = *reinterpret_cast<void**>(&v17 + 1);
                    v13 = 0;
                } else {
                    if (v13 == 3) {
                        v14 = reinterpret_cast<struct s0*>("Unable to move - outside bounds.");
                    } else {
                        fun_400850("FALSE", "game.c", 0xef, "game_AttemptMoveCommand");
                    }
                }
            }
        }
    } while (v13 && (v13 != 1 && v13 != 3));
    printf("%s \n\n", v14, "%s \n\n", v14);
    if (v13 != 1) {
        eax21 = 1;
    } else {
        eax21 = 0;
    }
    return eax21;
}

int64_t rand = 0x4008f6;

void* fun_4008f0(struct s0* rdi, struct s0* rsi, ...) {
    goto rand;
}

int64_t srand = 0x400876;

void fun_400870(int64_t rdi) {
    goto srand;
}

int32_t game_AttemptLoadCommand(struct s0* rdi, int64_t rsi, struct s0* rdx) {
    void* rbp4;
    struct s0* v5;
    struct s0* rcx6;
    int32_t eax7;
    void* rdi8;
    int32_t eax9;
    void* rdi10;
    int32_t eax11;
    int32_t eax12;

    rbp4 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(__zero_stack_offset()) - 8);
    v5 = rdi;
    while (rcx6 = reinterpret_cast<struct s0*>(reinterpret_cast<int64_t>(rbp4) + 0xffffffffffffffc0), getInput("At this stage of the program, only two commands are acceptable: \nload <g> \nquit \n\n", rcx6, 52), putchar(10, rcx6, 52), eax7 = strcmp(reinterpret_cast<int64_t>(rbp4) - 64, "quit", 52), !!eax7) {
        rdi8 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(rbp4) - 64);
        eax9 = strncmp(rdi8, "load", 4);
        if (eax9) {
            printInvalidInput(rdi8, "load", 4, rcx6);
        } else {
            rdi10 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(rbp4) - 64);
            eax11 = game_CommandLoad(rdi10, v5, v5);
            if (eax11 == 1) 
                goto addr_401042_6;
            printInvalidInput(rdi10, v5, v5, rcx6);
        }
    }
    eax12 = 0;
    addr_401071_9:
    return eax12;
    addr_401042_6:
    puts("Board successfully loaded\n", v5, v5, rcx6);
    eax12 = 1;
    goto addr_401071_9;
}

int64_t getInput(struct s0* rdi, struct s0* rsi, int32_t edx) {
    struct s0* v4;
    struct s0* v5;
    int32_t v6;
    struct s0* rdx7;
    struct s0* rcx8;
    struct s0* rsi9;
    int32_t eax10;
    int64_t rax11;

    v4 = rdi;
    v5 = rsi;
    v6 = edx;
    while (printf("%s", v4, "%s", v4), rdx7 = stdin, *reinterpret_cast<int32_t*>(&rcx8) = v6, *reinterpret_cast<int32_t*>(&rcx8 + 1) = 0, *reinterpret_cast<int32_t*>(&rsi9) = *reinterpret_cast<int32_t*>(&rcx8), *reinterpret_cast<int32_t*>(&rsi9 + 1) = 0, eax10 = readInput(v5, *reinterpret_cast<int32_t*>(&rsi9), rdx7), putchar(10, rsi9, rdx7), eax10 != 2) {
        printInvalidInput(10, rsi9, rdx7, rcx8);
    }
    *reinterpret_cast<int32_t*>(&rax11) = eax10;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax11) + 4) = 0;
    return rax11;
}

int32_t fun_4008d0(struct s0* rdi) {
    goto _IO_getc;
}

int64_t __libc_start_main = 0x400866;

void fun_400860(int64_t rdi, int64_t rsi, void* rdx, int64_t rcx, int64_t r8, int64_t r9, void** a7, int64_t a8) {
    goto __libc_start_main;
}



int64_t fun_400959() {
    if (!0 || 1) {
        return 0;
    } else {
        goto 0;
    }
}

/* completed.6354 */
signed char completed_6354 = 0;

int64_t __do_global_dtors_aux() {
    int1_t zf1;
    int64_t rax2;

    zf1 = completed_6354 == 0;
    if (zf1) {
        rax2 = deregister_tm_clones();
        completed_6354 = 1;
    }
    return rax2;
}

int64_t __JCR_END__ = 0;

void rand(int64_t rdi);

void frame_dummy() {
    int1_t zf1;

    zf1 = __JCR_END__ == 0;
    if (zf1 || 1) {
        goto 0x400960;
    } else {
        rand(0x602e20);
        goto 0x400960;
    }
}

void __libc_csu_fini() {
    return;
}

int64_t g603010 = 0;

void fun_4008a6() {
    goto g603010;
}

void fun_4007f6() {
    goto 0x4007e0;
}

void fun_400846() {
    goto 0x4007e0;
}

void fun_400816() {
    goto 0x4007e0;
}

void fun_400896() {
    goto 0x4007e0;
}

void fun_4008c6() {
    goto 0x4007e0;
}

void fun_400856() {
    goto 0x4007e0;
}

void fun_400806() {
    goto 0x4007e0;
}

void fun_4008e6() {
    goto 0x4007e0;
}

void fun_4008b6() {
    goto 0x4007e0;
}

int64_t main() {
    void* rbp1;
    int32_t v2;
    struct s0* rsi3;
    struct s0* rdx4;
    struct s0* rdi5;
    int32_t eax6;
    struct s0* rcx7;
    void* rdi8;
    int32_t eax9;
    struct s0* v10;
    uint32_t eax11;
    unsigned char* v12;

    rbp1 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(__zero_stack_offset()) - 8);
    enableWindowsCompatibility();
    v2 = 1;
    while (v2) {
        printf("Welcome to Hunt the Wumpus\n-------------------------- \n1. Play Game \n2. Show student information \n3. Quit \n\nPlease enter your choice: ", rsi3, "Welcome to Hunt the Wumpus\n-------------------------- \n1. Play Game \n2. Show student information \n3. Quit \n\nPlease enter your choice: ", rsi3);
        rdx4 = stdin;
        *reinterpret_cast<int32_t*>(&rsi3) = 3;
        *reinterpret_cast<int32_t*>(&rsi3 + 1) = 0;
        rdi5 = reinterpret_cast<struct s0*>(reinterpret_cast<int64_t>(rbp1) + 0xfffffffffffffff0);
        eax6 = readInput(rdi5, 3, rdx4, rdi5, 3, rdx4);
        putchar(10, 3, rdx4, 10, 3, rdx4);
        if (eax6 == 2) {
            rcx7 = reinterpret_cast<struct s0*>(reinterpret_cast<int64_t>(rbp1) + 0xffffffffffffffe8);
            rsi3 = rcx7;
            rdi8 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(rbp1) - 16);
            eax9 = strtol(rdi8, rsi3, 10);
            rdx4 = v10;
            if (rdx4 == reinterpret_cast<int64_t>(rbp1) + 0xfffffffffffffff0 || ((eax11 = *v12, !!*reinterpret_cast<signed char*>(&eax11)) || (eax9 <= 0 || eax9 > 3))) {
                printInvalidInput(rdi8, rsi3, rdx4, rcx7);
            } else {
                if (eax9 == 2) {
                    showStudentInformation(rdi8, rsi3);
                } else {
                    if (eax9 == 3) {
                        v2 = 0;
                    } else {
                        if (eax9 != 1) {
                            *reinterpret_cast<int32_t*>(&rcx7) = reinterpret_cast<int32_t>("main");
                            *reinterpret_cast<int32_t*>(&rcx7 + 1) = 0;
                            *reinterpret_cast<int32_t*>(&rdx4) = 57;
                            *reinterpret_cast<int32_t*>(&rdx4 + 1) = 0;
                            *reinterpret_cast<int32_t*>(&rsi3) = reinterpret_cast<int32_t>("huntWump.c");
                            *reinterpret_cast<int32_t*>(&rsi3 + 1) = 0;
                            fun_400850("FALSE", "huntWump.c", 57, "main");
                        } else {
                            game_PlayGame(rdi8, rsi3);
                        }
                    }
                }
            }
        } else {
            printInvalidInput(10, 3, rdx4, rcx7);
        }
    }
    puts("Good bye! \n", rsi3, rdx4, rcx7);
    return 0;
}

void fun_4008f6() {
    goto 0x4007e0;
}

void fun_400876() {
    goto 0x4007e0;
}

void fun_400886() {
    goto 0x4007e0;
}

void fun_400826() {
    goto 0x4007e0;
}

void player_UpdatePosition(int64_t* rdi, int64_t rsi) {
    *rdi = rsi;
    return;
}

void fun_400836() {
    goto 0x4007e0;
}

void __libc_csu_init(int32_t edi, int64_t rsi, int64_t rdx);

void _start() {
    void* rsp1;
    int64_t rdx2;
    int64_t rax3;

    rsp1 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(__zero_stack_offset()) + 8);
    fun_400860(main, __return_address(), rsp1, __libc_csu_init, __libc_csu_fini, rdx2, (reinterpret_cast<uint64_t>(rsp1) & 0xfffffffffffffff0) - 8 - 8, rax3);
    __asm__("hlt ");
}

void fun_4008d6() {
    goto 0x4007e0;
}

void __libc_csu_init(int32_t edi, int64_t rsi, int64_t rdx) {
    int32_t r15d4;
    int64_t r14_5;
    int64_t r13_6;
    int64_t rbx7;
    int64_t rdi8;

    r15d4 = edi;
    r14_5 = rsi;
    r13_6 = rdx;
    *reinterpret_cast<int32_t*>(&rbx7) = 0;
    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rbx7) + 4) = 0;
    _init();
    if (!0) {
        do {
            *reinterpret_cast<int32_t*>(&rdi8) = r15d4;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi8) + 4) = 0;
            *reinterpret_cast<int64_t*>(0x602e10 + rbx7 * 8)(rdi8, r14_5, r13_6);
            ++rbx7;
        } while (rbx7 != 1);
    }
    return;
}

void fun_400866() {
    goto 0x4007e0;
}
