
int64_t __gmon_start__ = 0;

void fun_400a20();

void _init() {
    int64_t rax1;

    rax1 = __gmon_start__;
    if (rax1) {
        fun_400a20();
    }
    return;
}

int64_t __gmon_start__ = 0x400a26;

void fun_400a20() {
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
    int32_t f4;
    struct s0* f8;
    signed char[4] pad16;
    struct s0* f16;
    signed char[4] pad24;
    struct s0* f24;
    signed char[4] pad32;
    int64_t f32;
    struct s0* f40;
};

int64_t fwrite = 0x400a86;

void fun_400a80(struct s0* rdi, struct s0* rsi, struct s0* rdx, struct s0* rcx, struct s0* r8) {
    goto fwrite;
}

void pop_node_free(struct s0* rdi, struct s0* rsi);

void fun_400960(struct s0* rdi, struct s0* rsi, ...);

void pop_free(struct s0* rdi, struct s0* rsi, struct s0* rdx, ...) {
    struct s0* v4;
    struct s0* v5;
    struct s0* v6;

    v4 = rdi;
    v5 = *reinterpret_cast<struct s0**>(&v4->f0);
    while (v5) {
        v6 = v5->f8;
        pop_node_free(v5, rsi);
        v5 = v6;
    }
    fun_400960(v4, rsi);
    return;
}

struct s1 {
    signed char[1004] pad1004;
    void* f1004;
};

void* invector_get_width(struct s1* rdi, int64_t rsi, struct s0* rdx) {
    return rdi->f1004;
}

struct s2 {
    signed char[1000] pad1000;
    struct s0* f1000;
};

struct s0* invector_get_num_invector(struct s2* rdi, int64_t rsi, struct s0* rdx) {
    return rdi->f1000;
}

int64_t freopen = 0x4009c6;

struct s0* fun_4009c0(int64_t rdi, int64_t rsi, struct s0* rdx) {
    goto freopen;
}

int64_t fclose = 0x4009a6;

void fun_4009a0(struct s0* rdi, struct s0* rsi, struct s0* rdx, struct s0* rcx, struct s0* r8) {
    goto fclose;
}

struct s3 {
    int32_t f0;
    int32_t f4;
};

int32_t invector_get_table_pos(struct s3* rdi, int32_t esi, int32_t edx) {
    int64_t rdx4;

    rdx4 = esi;
    return *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(rdi) + ((rdx4 << 2) + rdx4 + edx) * 4);
}

struct s0* fun_400a50(struct s0* rdi);

struct s0* stderr = reinterpret_cast<struct s0*>(0);

struct s0* gene_create_rand_gene(struct s0* edi, struct s0* rsi) {
    struct s0* rax3;
    int64_t rdi4;
    struct s0* rax5;
    struct s0* rax6;
    struct s0* r8_7;
    struct s0* rax8;

    rax3 = fun_400a50(32);
    if (!rax3 || (*reinterpret_cast<struct s0**>(&rdi4) = edi, *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdi4) + 4) = 0, rax5 = reinterpret_cast<struct s0*>(rsi(rdi4)), !rax5)) {
        rax6 = stderr;
        fun_400a80("Unable to allocate memory in gene_create_rand_gene\n", 1, 51, rax6, r8_7);
        *reinterpret_cast<int32_t*>(&rax8) = 0;
        *reinterpret_cast<int32_t*>(&rax8 + 1) = 0;
    } else {
        rax3->f8 = edi;
        *reinterpret_cast<struct s0**>(&rax3->f0) = rax5;
        rax3->f24 = reinterpret_cast<struct s0*>(0);
        rax3->f16 = reinterpret_cast<struct s0*>(0);
        rax8 = rax3;
    }
    return rax8;
}

struct s4 {
    int32_t f0;
    struct s0* f4;
};

struct s0* gene_normalise_fitness(struct s0* rdi, struct s0* rsi) {
    struct s4* rdi3;
    struct s4* rsi4;

    *reinterpret_cast<struct s0**>(&rdi->f0) = *reinterpret_cast<struct s0**>(&rsi->f0);
    rdi3 = reinterpret_cast<struct s4*>(&rdi->f4);
    rsi4 = reinterpret_cast<struct s4*>(&rsi->f4);
    rdi3->f0 = rsi4->f0;
    __asm__("divsd xmm0, [rbp-0x10]");
    *reinterpret_cast<struct s0**>(&rdi3->f4) = *reinterpret_cast<struct s0**>(&rsi4->f4);
    return rdi;
}

void gene_free(struct s0* rdi, struct s0* rsi) {
    struct s0* rdi3;

    rdi3 = *reinterpret_cast<struct s0**>(&rdi->f0);
    fun_400960(rdi3, rsi);
    fun_400960(rdi, rsi);
    return;
}

struct s0* stdout = reinterpret_cast<struct s0*>(0);

void fun_400a10(struct s0* rdi, struct s0* rsi, struct s0* rdx, struct s0* rcx);

void fun_4009d0(struct s0* rdi, struct s0* rsi, struct s0* rdx, struct s0* rcx);

void gene_print(struct s0* rdi, struct s0* rsi, struct s0* rdx) {
    struct s0* v4;
    struct s0* rax5;
    struct s0* rcx6;
    struct s0* rsi7;
    struct s0* rdi8;
    struct s0* r8_9;
    struct s0* v10;
    struct s0* rdx11;
    struct s0* rax12;
    struct s0* rax13;
    struct s0* rdx14;
    struct s0* rcx15;

    v4 = rdi;
    rax5 = stdout;
    rcx6 = rax5;
    *reinterpret_cast<int32_t*>(&rsi7) = 1;
    *reinterpret_cast<int32_t*>(&rsi7 + 1) = 0;
    *reinterpret_cast<int32_t*>(&rdi8) = reinterpret_cast<int32_t>("chrom:");
    *reinterpret_cast<int32_t*>(&rdi8 + 1) = 0;
    fun_400a80("chrom:", 1, 6, rcx6, r8_9);
    v10 = reinterpret_cast<struct s0*>(0);
    while (reinterpret_cast<int32_t>(v4->f8) > reinterpret_cast<int32_t>(v10)) {
        rdx11 = *reinterpret_cast<struct s0**>(reinterpret_cast<uint32_t>(*reinterpret_cast<struct s0**>(&v4->f0)) + (reinterpret_cast<uint64_t>(static_cast<int64_t>(reinterpret_cast<int32_t>(v10))) << 2));
        *reinterpret_cast<int32_t*>(&rdx11 + 1) = 0;
        rax12 = stdout;
        *reinterpret_cast<int32_t*>(&rsi7) = reinterpret_cast<int32_t>("%2d");
        *reinterpret_cast<int32_t*>(&rsi7 + 1) = 0;
        rdi8 = rax12;
        fun_400a10(rdi8, "%2d", rdx11, rcx6);
        if (reinterpret_cast<uint32_t>(v4->f8) - 1 != v10) {
            rax13 = stdout;
            rsi7 = rax13;
            *reinterpret_cast<int32_t*>(&rdi8) = 44;
            *reinterpret_cast<int32_t*>(&rdi8 + 1) = 0;
            fun_4009d0(44, rsi7, rdx11, rcx6);
        }
        v10 = reinterpret_cast<struct s0*>(reinterpret_cast<uint32_t>(v10) + 1);
    }
    rdx14 = v4->f16;
    rcx15 = stdout;
    *reinterpret_cast<struct s0**>(&rdi8->f0) = *reinterpret_cast<struct s0**>(&rsi7->f0);
    rdi8->f4 = rsi7->f4;
    fun_400a10(rcx15, " fit:%6.3f raw:%7.3f", rdx14, rcx15);
    return;
}

int64_t fputc = 0x4009d6;

void fun_4009d0(struct s0* rdi, struct s0* rsi, struct s0* rdx, struct s0* rcx) {
    goto fputc;
}

int64_t fprintf = 0x400a16;

void fun_400a10(struct s0* rdi, struct s0* rsi, struct s0* rdx, struct s0* rcx) {
    goto fprintf;
}

struct s5 {
    int32_t* f0;
    signed char[4] pad8;
    int32_t f8;
};

int32_t* gene_get_chrom(struct s5* rdi) {
    return rdi->f0;
}

int64_t free = 0x400966;

void fun_400960(struct s0* rdi, struct s0* rsi, ...) {
    goto free;
}

struct s6 {
    signed char[1000] pad1000;
    int32_t f1000;
    int32_t f1004;
};

void invector_init(struct s6* rdi) {
    rdi->f1000 = 0;
    rdi->f1004 = -1;
    return;
}

struct s0* gene_get_fitness(struct s0* rdi, struct s0* rsi, ...);

void pop_swap_gene(struct s0* rdi, struct s0* rsi);

struct s0* pop_sort(struct s0* rdi, struct s0* rsi) {
    struct s0* v3;
    struct s0* v4;
    int32_t v5;
    struct s0* v6;
    int1_t below_or_equal7;
    struct s0* rdi8;
    struct s0* rdi9;
    struct s0* rax10;

    v3 = rdi;
    v4 = reinterpret_cast<struct s0*>(0);
    if (v3) {
        do {
            v5 = 0;
            v6 = *reinterpret_cast<struct s0**>(&v3->f0);
            while (below_or_equal7 = reinterpret_cast<uint32_t>(v6->f8) <= reinterpret_cast<uint32_t>(v4), v6->f8 != v4) {
                rdi8 = *reinterpret_cast<struct s0**>(&v6->f0);
                gene_get_fitness(rdi8, rsi);
                *reinterpret_cast<struct s0**>(&rdi8->f0) = *reinterpret_cast<struct s0**>(&rsi->f0);
                rsi = reinterpret_cast<struct s0*>(&rsi->f4);
                rdi9 = *reinterpret_cast<struct s0**>(&v6->f8->f0);
                gene_get_fitness(rdi9, rsi);
                __asm__("ucomisd xmm0, [rbp-0x30]");
                if (!below_or_equal7) {
                    rsi = v6->f8;
                    pop_swap_gene(v6, rsi);
                    v5 = 1;
                }
                v6 = v6->f8;
            }
            v4 = v6;
        } while (v5);
        rax10 = v3;
    } else {
        *reinterpret_cast<int32_t*>(&rax10) = 0;
        *reinterpret_cast<int32_t*>(&rax10 + 1) = 0;
    }
    return rax10;
}

struct s0* gene_get_fitness(struct s0* rdi, struct s0* rsi, ...) {
    struct s0* rax3;

    rax3 = rdi->f24;
    *reinterpret_cast<struct s0**>(&rdi->f0) = *reinterpret_cast<struct s0**>(&rsi->f0);
    return rax3;
}

void pop_swap_gene(struct s0* rdi, struct s0* rsi) {
    struct s0* v3;

    v3 = *reinterpret_cast<struct s0**>(&rdi->f0);
    *reinterpret_cast<struct s0**>(&rdi->f0) = *reinterpret_cast<struct s0**>(&rsi->f0);
    *reinterpret_cast<struct s0**>(&rsi->f0) = v3;
    return;
}

int32_t pop_create_rand_pop(struct s0* rdi, struct s0* esi, struct s0* edx);

void pop_evaluate(struct s0* rdi, struct s0* rsi);

void pop_print_fittest(struct s0* rdi, struct s0* rsi);

struct s0* pop_reproduce(struct s0* rdi, struct s0* rsi);

void fun_400990(int64_t rdi, struct s0* rsi, struct s0* rdx);

struct s0* pop_run(struct s0* rdi, struct s0* esi, struct s0* edx, struct s0* ecx, struct s0* r8) {
    struct s0* v6;
    struct s0* v7;
    struct s0* v8;
    struct s0* rdx9;
    struct s0* rsi10;
    int32_t eax11;
    struct s0* v12;
    struct s0* rax13;
    struct s0* rax14;
    struct s0* rax15;

    v6 = rdi;
    v7 = ecx;
    v8 = r8;
    rdx9 = edx;
    *reinterpret_cast<int32_t*>(&rdx9 + 1) = 0;
    rsi10 = esi;
    *reinterpret_cast<int32_t*>(&rsi10 + 1) = 0;
    eax11 = pop_create_rand_pop(v6, rsi10, rdx9);
    if (eax11) {
        v12 = reinterpret_cast<struct s0*>(0);
        while (reinterpret_cast<int32_t>(v12) < reinterpret_cast<int32_t>(v7)) {
            pop_evaluate(v6, v8);
            rax13 = pop_sort(v6, v8);
            if (!rax13) 
                goto addr_4028be_5;
            pop_print_fittest(rax13, v8);
            rax14 = pop_reproduce(rax13, v8);
            if (!rax14) 
                goto addr_4028f2_7;
            pop_free(rax13, v8, v8);
            v6 = rax14;
            v12 = reinterpret_cast<struct s0*>(reinterpret_cast<uint32_t>(v12) + 1);
        }
    } else {
        fun_400990("pop_create_rand_pop failed", rsi10, rdx9);
        *reinterpret_cast<int32_t*>(&rax15) = 0;
        *reinterpret_cast<int32_t*>(&rax15 + 1) = 0;
        goto addr_40292b_10;
    }
    rax15 = v6;
    addr_40292b_10:
    return rax15;
    addr_4028be_5:
    fun_400990("pop_sort failed", v8, v8);
    *reinterpret_cast<int32_t*>(&rax15) = 0;
    *reinterpret_cast<int32_t*>(&rax15 + 1) = 0;
    goto addr_40292b_10;
    addr_4028f2_7:
    fun_400990("pop_reproduce failed", v8, v8);
    *reinterpret_cast<int32_t*>(&rax15) = 0;
    *reinterpret_cast<int32_t*>(&rax15 + 1) = 0;
    goto addr_40292b_10;
}

int64_t puts = 0x400996;

void fun_400990(int64_t rdi, struct s0* rsi, struct s0* rdx) {
    goto puts;
}

int32_t pop_init(struct s0** rdi) {
    struct s0* rax2;
    int32_t eax3;
    struct s0* rax4;
    struct s0* r8_5;

    rax2 = fun_400a50(48);
    if (rax2) {
        *reinterpret_cast<struct s0**>(&rax2->f0) = reinterpret_cast<struct s0*>(0);
        rax2->f8 = reinterpret_cast<struct s0*>(0);
        rax2->f16 = reinterpret_cast<struct s0*>(0);
        rax2->f24 = reinterpret_cast<struct s0*>(0);
        rax2->f32 = 0;
        rax2->f40 = reinterpret_cast<struct s0*>(0);
        *rdi = rax2;
        eax3 = 1;
    } else {
        rax4 = stderr;
        fun_400a80("pop_init: memory allocation failed", 1, 34, rax4, r8_5);
        eax3 = 0;
    }
    return eax3;
}

struct s7 {
    struct s0* f0;
    signed char[996] pad1000;
    struct s0* f1000;
    int32_t f1004;
};

struct s0* fun_400a60(struct s0* rdi, int64_t rsi);

int64_t fun_400a00(void* rdi, struct s0* rsi, struct s0* rdx);

struct s8 {
    signed char[1] pad1;
    struct s0* f1;
};

struct s8* fun_4009b0(struct s0* rdi, struct s0* rsi, struct s0* rdx);

int32_t invector_add(struct s7* rdi, struct s0* rsi, struct s0* rdx);

int32_t invector_load(struct s7* rdi, struct s0* rsi) {
    void* rbp3;
    struct s7* v4;
    struct s0* rax5;
    struct s0* v6;
    int64_t rax7;
    struct s8* rax8;
    uint32_t eax9;
    struct s0* rdx10;
    int32_t eax11;
    struct s0* rax12;
    struct s0* r8_13;
    int32_t eax14;
    struct s0* rcx15;
    struct s0* r8_16;
    struct s0* rax17;
    struct s0* r8_18;
    struct s0* rax19;
    struct s0* r8_20;
    struct s0* r8_21;
    struct s0* rcx22;
    struct s0* r8_23;

    rbp3 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(__zero_stack_offset()) - 8);
    v4 = rdi;
    rax5 = fun_400a60(rsi, "r");
    v6 = rax5;
    if (v6) {
        do {
            rax7 = fun_400a00(reinterpret_cast<int64_t>(rbp3) - 96, 82, v6);
            if (!rax7) 
                break;
            rax8 = fun_4009b0(reinterpret_cast<int64_t>(rbp3) + 0xffffffffffffffa0, 82, v6);
            eax9 = *reinterpret_cast<unsigned char*>(reinterpret_cast<int64_t>(rbp3) + (reinterpret_cast<int64_t>(rax8) - 1) - 96);
            if (*reinterpret_cast<signed char*>(&eax9) != 10) 
                goto addr_402081_5;
            rdx10 = reinterpret_cast<struct s0*>(reinterpret_cast<int64_t>(rbp3) + 0xffffffffffffffa0);
            eax11 = invector_add(v4, rdx10, rdx10);
        } while (eax11);
        goto addr_4020cc_7;
    } else {
        rax12 = stderr;
        fun_400a80("Failed to open invector file\n", 1, 29, rax12, r8_13);
        eax14 = 0;
        goto addr_402141_9;
    }
    fun_4009a0(v6, 82, v6, rcx15, r8_16);
    if (!reinterpret_cast<uint1_t>(reinterpret_cast<uint1_t>(reinterpret_cast<int32_t>(v4->f1000) < reinterpret_cast<int32_t>(0)) | reinterpret_cast<uint1_t>(v4->f1000 == 0))) {
        eax14 = 1;
    } else {
        rax17 = stderr;
        fun_400a80("Error: must have at least 1 invector\n", 1, 37, rax17, r8_18);
        eax14 = 0;
    }
    addr_402141_9:
    return eax14;
    addr_402081_5:
    rax19 = stderr;
    fun_400a80("Error: invector line too long\n", 1, 30, rax19, r8_20);
    fun_4009a0(v6, 1, 30, rax19, r8_21);
    eax14 = 0;
    goto addr_402141_9;
    addr_4020cc_7:
    fun_4009a0(v6, rdx10, rdx10, rcx22, r8_23);
    eax14 = 0;
    goto addr_402141_9;
}

int64_t strtol = 0x400a36;

struct s0* fun_400a30(unsigned char* rdi, void* rsi, struct s0* rdx) {
    goto strtol;
}

int64_t strncmp = 0x400986;

int32_t fun_400980(unsigned char* rdi, int64_t rsi, struct s0* rdx) {
    goto strncmp;
}

struct s9 {
    int32_t f0;
    int32_t f4;
};

struct s9* invector_get_table_row(int32_t* rdi, int32_t esi) {
    int64_t rdx3;

    rdx3 = esi;
    return ((rdx3 << 2) + rdx3 << 2) + reinterpret_cast<int64_t>(rdi);
}

struct s10 {
    signed char[16] pad16;
    struct s0* f16;
    signed char[4] pad24;
    struct s0* f24;
    signed char[4] pad32;
    int64_t f32;
    struct s0* f40;
};

void pop_set_fns(struct s10* rdi, struct s0* rsi, struct s0* rdx, int64_t rcx, struct s0* r8) {
    rdi->f16 = rsi;
    rdi->f24 = rdx;
    rdi->f32 = rcx;
    rdi->f40 = r8;
    return;
}

int64_t rand = 0x400aa6;

void* fun_400aa0(struct s0* rdi, struct s0* rsi, ...) {
    goto rand;
}

struct s11 {
    signed char[1] pad1;
    struct s0* f1;
};

void gene_swap_alleles(struct s0* rdi, struct s11* esi, int32_t edx) {
    struct s0* v4;

    v4 = *reinterpret_cast<struct s0**>(reinterpret_cast<uint32_t>(rdi) + reinterpret_cast<int32_t>(esi) * 4);
    *reinterpret_cast<struct s0**>(reinterpret_cast<int32_t>(esi) * 4 + reinterpret_cast<uint32_t>(rdi)) = *reinterpret_cast<struct s0**>(reinterpret_cast<uint32_t>(rdi) + edx * 4);
    *reinterpret_cast<struct s0**>(edx * 4 + reinterpret_cast<uint32_t>(rdi)) = v4;
    return;
}

int32_t gene_chrom_contains(struct s0* rdi, int32_t esi, struct s0* edx) {
    struct s0* v4;
    int32_t v5;
    struct s0* v6;
    int32_t v7;
    int32_t eax8;

    v4 = rdi;
    v5 = esi;
    v6 = edx;
    v7 = 0;
    while (v7 <= v5) {
        if (*reinterpret_cast<struct s0**>(reinterpret_cast<uint32_t>(v4) + v7 * 4) == v6) 
            goto addr_401a2e_4;
        ++v7;
    }
    eax8 = 0;
    addr_401a46_7:
    return eax8;
    addr_401a2e_4:
    eax8 = 1;
    goto addr_401a46_7;
}

void fun_400a90();

int64_t pcbmill_distance(struct s9* rdi, struct s9* rsi) {
    int64_t v3;

    __asm__("cvtsi2sd xmm0, eax");
    fun_400a90();
    rdi->f0 = rsi->f0;
    rdi->f4 = rsi->f4;
    return v3;
}

int64_t fun_400970(struct s0* rdi, struct s0* rsi, struct s0* rdx);

unsigned char* fun_400a70(struct s0* rdi, struct s0* rsi, struct s0* rdx);

unsigned char g402c86 = 10;

int32_t invector_add(struct s7* rdi, struct s0* rsi, struct s0* rdx) {
    void* rbp4;
    struct s7* v5;
    int32_t v6;
    struct s8* rax7;
    struct s0* rax8;
    struct s0* v9;
    struct s8* rax10;
    struct s0* rdx11;
    int64_t rax12;
    unsigned char* rax13;
    int32_t eax14;
    unsigned char* rax15;
    struct s0* rdx16;
    struct s0* eax17;
    struct s0* v18;
    uint32_t eax19;
    unsigned char* v20;
    unsigned char* rax21;
    uint32_t eax22;
    int64_t rbx23;
    struct s0* eax24;
    uint32_t eax25;
    unsigned char* v26;
    struct s0* rax27;
    struct s0* r8_28;
    int32_t eax29;
    struct s0* rax30;
    struct s0* r8_31;
    struct s0* rax32;
    struct s0* r8_33;
    struct s0* rax34;
    struct s0* r8_35;
    struct s0* rax36;
    struct s0* r8_37;
    struct s0* rax38;
    struct s0* r8_39;
    struct s0* rax40;
    struct s0* r8_41;
    struct s0* rax42;
    struct s0* r8_43;
    int64_t rax44;
    struct s0* rax45;
    struct s0* r8_46;
    struct s0* rax47;
    struct s0* r8_48;
    struct s0* rax49;
    struct s0* r8_50;
    struct s0* rax51;
    struct s0* r8_52;

    rbp4 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(__zero_stack_offset()) - 8);
    v5 = rdi;
    v6 = 0;
    if (reinterpret_cast<int32_t>(v5->f1000) <= reinterpret_cast<int32_t>(49)) {
        rax7 = fun_4009b0(rsi, rsi, rdx);
        rax8 = fun_400a50(&rax7->f1);
        v9 = rax8;
        if (v9) {
            rax10 = fun_4009b0(rsi, rsi, rdx);
            rdx11 = reinterpret_cast<struct s0*>(&rax10->f1);
            rax12 = fun_400970(v9, rsi, rdx11);
            if (rax12) {
                rax13 = fun_400a70(v9, ":", rdx11);
                if (rax13) {
                    eax14 = fun_400980(rax13, "InputVector", 12);
                    if (!eax14) {
                        rax15 = fun_400a70(0, "(", 12);
                        if (rax15) {
                            *reinterpret_cast<uint32_t*>(&rdx16) = 10;
                            *reinterpret_cast<int32_t*>(&rdx16 + 1) = 0;
                            eax17 = fun_400a30(rax15, reinterpret_cast<int64_t>(rbp4) - 56, 10);
                            v18 = eax17;
                            eax19 = *v20;
                            if (!*reinterpret_cast<signed char*>(&eax19)) {
                                if (v5->f1000 == v18) {
                                    do {
                                        addr_401f25_10:
                                        rax21 = fun_400a70(0, ",)", rdx16);
                                        if (!rax21) 
                                            break;
                                        *reinterpret_cast<uint32_t*>(&rdx16) = g402c86;
                                        *reinterpret_cast<int32_t*>(&rdx16 + 1) = 0;
                                        eax22 = *rax21;
                                        if (*reinterpret_cast<signed char*>(&rdx16) == *reinterpret_cast<signed char*>(&eax22)) 
                                            goto addr_401f25_10;
                                        if (v6 == 5) 
                                            goto addr_401e72_13;
                                        *reinterpret_cast<int32_t*>(&rbx23) = v6;
                                        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rbx23) + 4) = 0;
                                        v6 = static_cast<int32_t>(rbx23 + 1);
                                        eax24 = fun_400a30(rax21, reinterpret_cast<int64_t>(rbp4) - 56, 10);
                                        rdx16 = reinterpret_cast<struct s0*>(static_cast<int64_t>(reinterpret_cast<int32_t>(v18)));
                                        *reinterpret_cast<struct s0**>(reinterpret_cast<int64_t>(v5) + (reinterpret_cast<uint64_t>(reinterpret_cast<uint32_t>(rdx16) << 2) + reinterpret_cast<uint32_t>(rdx16) + static_cast<int64_t>(*reinterpret_cast<int32_t*>(&rbx23))) * 4) = eax24;
                                        eax25 = *v26;
                                    } while (!*reinterpret_cast<signed char*>(&eax25));
                                    goto addr_401ef1_15;
                                } else {
                                    rax27 = stderr;
                                    fun_400a80("Error: invector string invalid\n", 1, 31, rax27, r8_28);
                                    fun_400960(v9, 1, v9, 1);
                                    eax29 = 0;
                                    goto addr_402003_17;
                                }
                            } else {
                                rax30 = stderr;
                                fun_400a80("Error: invector string invalid\n", 1, 31, rax30, r8_31);
                                fun_400960(v9, 1, v9, 1);
                                eax29 = 0;
                                goto addr_402003_17;
                            }
                        } else {
                            rax32 = stderr;
                            fun_400a80("Error: invector string invalid\n", 1, 31, rax32, r8_33);
                            fun_400960(v9, 1, v9, 1);
                            eax29 = 0;
                            goto addr_402003_17;
                        }
                    } else {
                        rax34 = stderr;
                        fun_400a80("Error: invector string invalid\n", 1, 31, rax34, r8_35);
                        fun_400960(v9, 1, v9, 1);
                        eax29 = 0;
                        goto addr_402003_17;
                    }
                } else {
                    rax36 = stderr;
                    fun_400a80("Error: invector string invalid\n", 1, 31, rax36, r8_37);
                    fun_400960(v9, 1, v9, 1);
                    eax29 = 0;
                    goto addr_402003_17;
                }
            } else {
                rax38 = stderr;
                fun_400a80("Unable to duplicate string\n", 1, 27, rax38, r8_39);
                fun_400960(v9, 1, v9, 1);
                eax29 = 0;
                goto addr_402003_17;
            }
        } else {
            rax40 = stderr;
            fun_400a80("Unable to duplicate string\n", 1, 27, rax40, r8_41);
            eax29 = 0;
            goto addr_402003_17;
        }
    } else {
        rax42 = stderr;
        fun_400a80("Error: invector table full\n", 1, 27, rax42, r8_43);
        eax29 = 0;
        goto addr_402003_17;
    }
    if (v6) {
        *reinterpret_cast<struct s0**>(&rax44) = v5->f1000;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax44) + 4) = 0;
        v5->f1000 = reinterpret_cast<struct s0*>(static_cast<uint32_t>(rax44 + 1));
        if (v5->f1004 != -1) {
            if (v5->f1004 == v6) {
                addr_401ff2_28:
                fun_400960(v9, ",)");
                eax29 = 1;
            } else {
                rax45 = stderr;
                fun_400a80("Error: invector string invalid\n", 1, 31, rax45, r8_46);
                fun_400960(v9, 1, v9, 1);
                eax29 = 0;
            }
        } else {
            v5->f1004 = v6;
            goto addr_401ff2_28;
        }
    } else {
        rax47 = stderr;
        fun_400a80("Error: invector string invalid\n", 1, 31, rax47, r8_48);
        fun_400960(v9, 1, v9, 1);
        eax29 = 0;
    }
    addr_402003_17:
    return eax29;
    addr_401e72_13:
    rax49 = stderr;
    fun_400a80("Error: invector string invalid\n", 1, 31, rax49, r8_50);
    fun_400960(v9, 1, v9, 1);
    eax29 = 0;
    goto addr_402003_17;
    addr_401ef1_15:
    rax51 = stderr;
    fun_400a80("Error: invector string invalid\n", 1, 31, rax51, r8_52);
    fun_400960(v9, 1, v9, 1);
    eax29 = 0;
    goto addr_402003_17;
}

int64_t malloc = 0x400a56;

struct s0* fun_400a50(struct s0* rdi) {
    goto malloc;
}

struct s0* gene_calc_fitness(struct s0* rdi, struct s0* rsi, struct s0* rdx) {
    struct s4* rdi4;
    struct s4* rsi5;
    struct s0* v6;
    struct s0* rdi7;
    struct s0* rsi8;
    struct s4* rdi9;
    struct s4* rsi10;

    rsi();
    *reinterpret_cast<struct s0**>(&rdx->f0) = *reinterpret_cast<struct s0**>(&rdi->f0);
    rdi4 = reinterpret_cast<struct s4*>(&rdx->f4);
    rsi5 = reinterpret_cast<struct s4*>(&rdi->f4);
    rdi->f16 = v6;
    rdi4->f0 = rsi5->f0;
    rdi7 = reinterpret_cast<struct s0*>(&rdi4->f4);
    rsi8 = reinterpret_cast<struct s0*>(&rsi5->f4);
    *reinterpret_cast<struct s0**>(&rdi7->f0) = *reinterpret_cast<struct s0**>(&rsi8->f0);
    rdi9 = reinterpret_cast<struct s4*>(&rdi7->f4);
    rsi10 = reinterpret_cast<struct s4*>(&rsi8->f4);
    __asm__("addsd xmm0, xmm1");
    rdi9->f0 = rsi10->f0;
    __asm__("divsd xmm1, xmm0");
    __asm__("movapd xmm0, xmm1");
    *reinterpret_cast<struct s0**>(&rdi9->f4) = *reinterpret_cast<struct s0**>(&rsi10->f4);
    return rdi;
}

int32_t gene_get_num_alleles(struct s5* rdi) {
    return rdi->f8;
}

int64_t memcpy = 0x400a46;

void fun_400a40(struct s0* rdi, struct s0* rsi, int64_t rdx) {
    goto memcpy;
}

int64_t strlen = 0x4009b6;

struct s8* fun_4009b0(struct s0* rdi, struct s0* rsi, struct s0* rdx) {
    goto strlen;
}

int64_t strncpy = 0x400976;

int64_t fun_400970(struct s0* rdi, struct s0* rsi, struct s0* rdx) {
    goto strncpy;
}

int64_t strtok = 0x400a76;

unsigned char* fun_400a70(struct s0* rdi, struct s0* rsi, struct s0* rdx) {
    goto strtok;
}

int64_t fgets = 0x400a06;

int64_t fun_400a00(void* rdi, struct s0* rsi, struct s0* rdx) {
    goto fgets;
}

int32_t pop_insert(struct s0* rdi, struct s0* rsi, ...);

int32_t pop_create_rand_pop(struct s0* rdi, struct s0* esi, struct s0* edx) {
    struct s0* v4;
    struct s0* v5;
    struct s0* v6;
    struct s0* v7;
    struct s0* rdx8;
    struct s0* rax9;
    int32_t eax10;

    v4 = rdi;
    v5 = esi;
    v6 = edx;
    v7 = reinterpret_cast<struct s0*>(0);
    while (reinterpret_cast<int32_t>(v7) < reinterpret_cast<int32_t>(v5)) {
        rdx8 = v4->f16;
        rax9 = gene_create_rand_gene(v6, rdx8);
        if (!rax9) 
            goto addr_4022ed_4;
        pop_insert(v4, rax9);
        v7 = reinterpret_cast<struct s0*>(reinterpret_cast<uint32_t>(v7) + 1);
    }
    eax10 = 1;
    addr_402324_7:
    return eax10;
    addr_4022ed_4:
    pop_free(v4, rdx8, rdx8);
    eax10 = 0;
    goto addr_402324_7;
}

void pop_evaluate(struct s0* rdi, struct s0* rsi) {
    struct s0* v3;
    struct s0* v4;
    struct s0* v5;
    struct s0* v6;
    struct s0* rsi7;
    struct s4* rdi8;
    struct s4* rsi9;
    struct s0* v10;
    struct s0* rdx11;

    v3 = rdi;
    v4 = rsi;
    v5 = *reinterpret_cast<struct s0**>(&v3->f0);
    while (v5) {
        v6 = *reinterpret_cast<struct s0**>(&v5->f0);
        rsi7 = v3->f40;
        gene_calc_fitness(v6, rsi7, v4);
        gene_get_fitness(v6, rsi7, v6, rsi7);
        *reinterpret_cast<struct s0**>(&v6->f0) = *reinterpret_cast<struct s0**>(&rsi7->f0);
        rdi8 = reinterpret_cast<struct s4*>(&v6->f4);
        rsi9 = reinterpret_cast<struct s4*>(&rsi7->f4);
        __asm__("addsd xmm0, xmm1");
        rdi8->f0 = rsi9->f0;
        rdi = reinterpret_cast<struct s0*>(&rdi8->f4);
        rsi = reinterpret_cast<struct s0*>(&rsi9->f4);
        v5 = v5->f8;
    }
    v10 = *reinterpret_cast<struct s0**>(&v3->f0);
    while (v10) {
        rdx11 = *reinterpret_cast<struct s0**>(&v10->f0);
        *reinterpret_cast<struct s0**>(&rdi->f0) = *reinterpret_cast<struct s0**>(&rsi->f0);
        rsi = reinterpret_cast<struct s0*>(&rsi->f4);
        rdi = rdx11;
        gene_normalise_fitness(rdi, rsi);
        v10 = v10->f8;
    }
    return;
}

int32_t pop_insert(struct s0* rdi, struct s0* rsi, ...) {
    struct s0* rax3;
    int64_t rax4;
    int32_t eax5;
    struct s0* rax6;
    struct s0* r8_7;

    rax3 = fun_400a50(16);
    if (rax3) {
        rax3->f8 = *reinterpret_cast<struct s0**>(&rdi->f0);
        *reinterpret_cast<struct s0**>(&rdi->f0) = rax3;
        *reinterpret_cast<struct s0**>(&rax3->f0) = rsi;
        *reinterpret_cast<struct s0**>(&rax4) = rdi->f8;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax4) + 4) = 0;
        rdi->f8 = reinterpret_cast<struct s0*>(static_cast<uint32_t>(rax4 + 1));
        eax5 = 1;
    } else {
        rax6 = stderr;
        fun_400a80("failed to allocate memory in pop_insert\n", 1, 40, rax6, r8_7);
        eax5 = 0;
    }
    return eax5;
}

struct s0* pop_proportionate_select(struct s0* rdi, struct s0* rsi) {
    struct s4* rsi3;
    struct s0* rsi4;
    struct s0* v5;
    int1_t below_or_equal6;
    struct s0* rdi7;
    struct s4* rdi8;
    struct s4* rsi9;
    struct s0* rdi10;
    struct s0* rsi11;
    struct s4* rsi12;
    struct s0* rax13;

    fun_400aa0(rdi, rsi);
    __asm__("cvtsi2sd xmm0, eax");
    *reinterpret_cast<struct s0**>(&rdi->f0) = *reinterpret_cast<struct s0**>(&rsi->f0);
    rsi3 = reinterpret_cast<struct s4*>(&rsi->f4);
    __asm__("divsd xmm0, xmm1");
    rdi->f4 = rsi3->f0;
    rsi4 = reinterpret_cast<struct s0*>(&rsi3->f4);
    v5 = *reinterpret_cast<struct s0**>(&rdi->f0);
    below_or_equal6 = reinterpret_cast<uint32_t>(v5) <= reinterpret_cast<uint32_t>(0);
    if (v5) {
        do {
            rdi7 = *reinterpret_cast<struct s0**>(&v5->f0);
            gene_get_fitness(rdi7, rsi4);
            *reinterpret_cast<struct s0**>(&rdi7->f0) = *reinterpret_cast<struct s0**>(&rsi4->f0);
            rdi8 = reinterpret_cast<struct s4*>(&rdi7->f4);
            rsi9 = reinterpret_cast<struct s4*>(&rsi4->f4);
            __asm__("addsd xmm0, xmm1");
            rdi8->f0 = rsi9->f0;
            rdi10 = reinterpret_cast<struct s0*>(&rdi8->f4);
            rsi11 = reinterpret_cast<struct s0*>(&rsi9->f4);
            *reinterpret_cast<struct s0**>(&rdi10->f0) = *reinterpret_cast<struct s0**>(&rsi11->f0);
            rsi12 = reinterpret_cast<struct s4*>(&rsi11->f4);
            __asm__("ucomisd xmm0, [rbp-0x10]");
            if (!below_or_equal6) {
                v5 = v5->f8;
            }
            below_or_equal6 = reinterpret_cast<uint32_t>(v5) <= reinterpret_cast<uint32_t>(0);
            if (!v5) 
                break;
            rdi10->f4 = rsi12->f0;
            rsi4 = reinterpret_cast<struct s0*>(&rsi12->f4);
            __asm__("ucomisd xmm0, [rbp-0x10]");
        } while (!below_or_equal6);
        rax13 = *reinterpret_cast<struct s0**>(&v5->f0);
    } else {
        *reinterpret_cast<int32_t*>(&rax13) = 0;
        *reinterpret_cast<int32_t*>(&rax13 + 1) = 0;
    }
    return rax13;
}

struct s0* gene_copy(struct s0* rdi, struct s0* rsi, struct s0* rdx, int64_t rcx, struct s0* r8);

struct s0* pop_reproduce(struct s0* rdi, struct s0* rsi) {
    struct s0* v3;
    int32_t eax4;
    int64_t rcx5;
    struct s0* rdx6;
    struct s0* rsi7;
    struct s0* r8_8;
    struct s10* v9;
    struct s0* rdi10;
    struct s0* rax11;
    struct s0* rdx12;
    struct s0* rsi13;
    struct s0* v14;
    int32_t eax15;
    struct s0* v16;
    struct s0* rax17;
    struct s0* rax18;
    int64_t rax19;
    struct s0* rax20;
    struct s0* v21;
    void* eax22;
    struct s0* rax23;
    struct s0* rax24;
    struct s0* v25;
    int32_t eax26;
    struct s0* v27;
    struct s0* rax28;
    struct s0* v29;
    struct s0* v30;
    struct s0* v31;
    struct s0* v32;
    struct s0* v33;
    struct s0* v34;

    v3 = rdi;
    if (v3) {
        eax4 = pop_init(reinterpret_cast<int64_t>(__zero_stack_offset()) - 8 - 48);
        if (eax4) {
            rcx5 = v3->f32;
            rdx6 = v3->f24;
            rsi7 = v3->f16;
            r8_8 = v3->f40;
            pop_set_fns(v9, rsi7, rdx6, rcx5, r8_8);
            rdi10 = *reinterpret_cast<struct s0**>(&(*reinterpret_cast<struct s0**>(&v3->f0))->f0);
            rax11 = gene_copy(rdi10, rsi7, rdx6, rcx5, r8_8);
            if (rax11) {
                rdx12 = rax11;
                rsi13 = rdx12;
                eax15 = pop_insert(v14, rsi13, v14, rsi13);
                if (eax15) {
                    v16 = reinterpret_cast<struct s0*>(1);
                    while (reinterpret_cast<int32_t>(v3->f8) > reinterpret_cast<int32_t>(v16)) {
                        rax17 = pop_proportionate_select(v3, rsi13);
                        rax18 = pop_proportionate_select(v3, rsi13);
                        if (!rax17) 
                            goto addr_40265e_8;
                        if (!rax18) 
                            goto addr_40265e_8;
                        rax19 = v3->f32;
                        rax20 = reinterpret_cast<struct s0*>(rax19(rax17, rax18));
                        v21 = rax20;
                        if (!v21) 
                            goto addr_402697_11;
                        eax22 = fun_400aa0(rax17, rax18);
                        if (reinterpret_cast<int32_t>(eax22) - ((__intrinsic() >> 5) - (reinterpret_cast<int32_t>(eax22) >> 31)) * 100 <= 4) {
                            rax23 = v3->f24;
                            rax24 = reinterpret_cast<struct s0*>(rax23(v21, rax18));
                            if (!rax24) 
                                goto addr_4026f1_14;
                            gene_free(v21, rax18);
                            v21 = rax24;
                        }
                        rdx12 = v21;
                        rsi13 = rdx12;
                        eax26 = pop_insert(v25, rsi13);
                        if (!eax26) 
                            goto addr_40272f_17;
                        v16 = reinterpret_cast<struct s0*>(reinterpret_cast<uint32_t>(v16) + 1);
                    }
                } else {
                    pop_free(v27, rsi13, rdx12, v27, rsi13, rdx12);
                    *reinterpret_cast<int32_t*>(&rax28) = 0;
                    *reinterpret_cast<int32_t*>(&rax28 + 1) = 0;
                    goto addr_40275a_20;
                }
            } else {
                pop_free(v29, rsi7, rdx6, v29, rsi7, rdx6);
                *reinterpret_cast<int32_t*>(&rax28) = 0;
                *reinterpret_cast<int32_t*>(&rax28 + 1) = 0;
                goto addr_40275a_20;
            }
        } else {
            *reinterpret_cast<int32_t*>(&rax28) = 0;
            *reinterpret_cast<int32_t*>(&rax28 + 1) = 0;
            goto addr_40275a_20;
        }
    } else {
        *reinterpret_cast<int32_t*>(&rax28) = 0;
        *reinterpret_cast<int32_t*>(&rax28 + 1) = 0;
        goto addr_40275a_20;
    }
    rax28 = v30;
    addr_40275a_20:
    return rax28;
    addr_40265e_8:
    pop_free(v31, rsi13, rdx12, v31, rsi13, rdx12);
    *reinterpret_cast<int32_t*>(&rax28) = 0;
    *reinterpret_cast<int32_t*>(&rax28 + 1) = 0;
    goto addr_40275a_20;
    addr_402697_11:
    pop_free(v32, rax18, rax17);
    *reinterpret_cast<int32_t*>(&rax28) = 0;
    *reinterpret_cast<int32_t*>(&rax28 + 1) = 0;
    goto addr_40275a_20;
    addr_40272f_17:
    pop_free(v33, rsi13, rdx12);
    *reinterpret_cast<int32_t*>(&rax28) = 0;
    *reinterpret_cast<int32_t*>(&rax28 + 1) = 0;
    goto addr_40275a_20;
    addr_4026f1_14:
    pop_free(v34, rax18, v21);
    *reinterpret_cast<int32_t*>(&rax28) = 0;
    *reinterpret_cast<int32_t*>(&rax28 + 1) = 0;
    goto addr_40275a_20;
}

/* gen.2205 */
int32_t gen_2205 = 0;

void pop_print_fittest(struct s0* rdi, struct s0* rsi) {
    struct s0* v3;
    struct s0* rdx4;
    struct s0* rax5;
    struct s0* rcx6;
    struct s0* rdi7;
    struct s0* rax8;
    struct s0* rcx9;
    int32_t eax10;
    struct s0* rax11;
    struct s0* r8_12;

    v3 = *reinterpret_cast<struct s0**>(&rdi->f0);
    if (v3) {
        *reinterpret_cast<int32_t*>(&rdx4) = gen_2205;
        *reinterpret_cast<int32_t*>(&rdx4 + 1) = 0;
        rax5 = stdout;
        fun_400a10(rax5, "Gen:%4d ", rdx4, rcx6);
        rdi7 = *reinterpret_cast<struct s0**>(&v3->f0);
        gene_print(rdi7, "Gen:%4d ", rdx4);
        rax8 = stdout;
        fun_4009d0(10, rax8, rdx4, rcx9);
        eax10 = gen_2205;
        gen_2205 = eax10 + 1;
    } else {
        rax11 = stderr;
        fun_400a80("pop_print_fittest: pop is empty\n", 1, 32, rax11, r8_12);
    }
    return;
}

struct s0* gene_copy(struct s0* rdi, struct s0* rsi, struct s0* rdx, int64_t rcx, struct s0* r8) {
    struct s0* rax6;
    struct s0* rdi7;
    struct s0* rax8;
    int64_t rdx9;
    struct s0* rsi10;
    struct s0* rdi11;
    struct s0* rax12;
    struct s0* rax13;
    struct s0* rax14;

    rax6 = fun_400a50(32);
    if (rax6) {
        rdi7 = reinterpret_cast<struct s0*>(reinterpret_cast<uint64_t>(static_cast<int64_t>(reinterpret_cast<int32_t>(rdi->f8))) << 2);
        rax8 = fun_400a50(rdi7);
        if (rax8) {
            *reinterpret_cast<struct s0**>(&rax6->f0) = rax8;
            rax6->f8 = rdi->f8;
            rax6->f24 = rdi->f24;
            rax6->f16 = rdi->f16;
            rdx9 = reinterpret_cast<int32_t>(rdi->f8) * 4;
            rsi10 = *reinterpret_cast<struct s0**>(&rdi->f0);
            rdi11 = *reinterpret_cast<struct s0**>(&rax6->f0);
            fun_400a40(rdi11, rsi10, rdx9);
            rax12 = rax6;
        } else {
            rax13 = stderr;
            fun_400a80("Unable to allocate memory in gene_copy\n", 1, 39, rax13, r8);
            fun_400960(rax6, 1, rax6, 1);
            *reinterpret_cast<int32_t*>(&rax12) = 0;
            *reinterpret_cast<int32_t*>(&rax12 + 1) = 0;
        }
    } else {
        rax14 = stderr;
        fun_400a80("Unable to allocate memory in gene_copy\n", 1, 39, rax14, r8);
        *reinterpret_cast<int32_t*>(&rax12) = 0;
        *reinterpret_cast<int32_t*>(&rax12 + 1) = 0;
    }
    return rax12;
}

void pop_node_free(struct s0* rdi, struct s0* rsi) {
    struct s0* rdi3;

    rdi3 = *reinterpret_cast<struct s0**>(&rdi->f0);
    gene_free(rdi3, rsi);
    fun_400960(rdi, rsi);
    return;
}

int64_t srand = 0x4009f6;

void fun_4009f0(int64_t rdi) {
    goto srand;
}

int64_t sqrt = 0x400a96;

void fun_400a90() {
    goto sqrt;
}

int64_t fopen = 0x400a66;

struct s0* fun_400a60(struct s0* rdi, int64_t rsi) {
    goto fopen;
}

int64_t __libc_start_main = 0x4009e6;

void fun_4009e0(int64_t rdi, int64_t rsi, void* rdx, int64_t rcx, int64_t r8, int64_t r9, void** a7, int64_t a8) {
    goto __libc_start_main;
}

void _fini() {
    return;
}

int64_t fun_400b09() {
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
        goto 0x400b10;
    } else {
        rand(0x603e10);
        goto 0x400b10;
    }
}

int32_t rand;

int32_t g4;

int64_t eval_minfn(struct s3* rdi, struct s5* rsi) {
    struct s3* v3;
    int32_t v4;
    int32_t v5;
    int64_t v6;

    v3 = rdi;
    gene_get_chrom(rsi);
    v4 = rsi->f8;
    v5 = 0;
    while (v5 < v4) {
        invector_get_table_pos(v3, 0, v5);
        ++v5;
    }
    invector_get_table_pos(v3, 0, v5);
    __asm__("cvtsi2sd xmm0, dword [rbp-0x18]");
    v3->f0 = rand;
    v3->f4 = g4;
    return v6;
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
            *reinterpret_cast<int64_t*>(0x603e00 + rbx7 * 8)(rdi8, r14_5, r13_6);
            ++rbx7;
        } while (rbx7 != 1);
    }
    return;
}

void __libc_csu_fini() {
    return;
}

int64_t g604010 = 0;

void fun_400a26() {
    goto g604010;
}

struct s12 {
    signed char[8] pad8;
    unsigned char* f8;
    unsigned char* f16;
    unsigned char* f24;
    unsigned char* f32;
    struct s0* f40;
    signed char[4] pad48;
    int64_t f48;
};

int64_t eval_pcbmill(int32_t* rdi, struct s5* rsi);

struct s0* create_pcbmill_chrom(struct s0* edi);

struct s0* mutate_pcbmill(struct s0* rdi, struct s0* rsi, struct s0* rdx, int64_t rcx, struct s0* r8);

struct s0* crossover_pcbmill(struct s0* rdi, struct s0* rsi, struct s0* rdx, int64_t rcx, struct s0* r8);

struct s0* create_minfn_chrom(int32_t edi, struct s0* rsi);

struct s0* mutate_minfn(struct s0* rdi, struct s0* rsi, struct s0* rdx, int64_t rcx, struct s0* r8);

struct s0* crossover_minfn(struct s0* rdi, struct s0* rsi, struct s0* rdx, int64_t rcx, struct s0* r8);

int64_t main(int32_t edi, struct s12* rsi) {
    void* rbp3;
    struct s0* v4;
    struct s0* rax5;
    struct s0* r8_6;
    int64_t rax7;
    int32_t eax8;
    struct s0* rdx9;
    int32_t eax10;
    unsigned char* rdi11;
    struct s0* eax12;
    unsigned char* v13;
    uint32_t eax14;
    unsigned char* v15;
    struct s0* rax16;
    struct s0* r8_17;
    struct s0* v18;
    unsigned char* rdi19;
    int32_t eax20;
    unsigned char* rdi21;
    int32_t eax22;
    struct s0* rax23;
    struct s0* r8_24;
    struct s0* eax25;
    struct s0* r8_26;
    struct s10* v27;
    struct s0* rax28;
    struct s0* r8_29;
    struct s0* v30;
    void* eax31;
    struct s0* eax32;
    struct s10* v33;
    struct s0* rax34;
    struct s0* r8_35;
    struct s0* v36;
    struct s0* rax37;
    struct s0* r8_38;
    struct s0* v39;
    struct s0* v40;
    unsigned char* rdi41;
    struct s0* eax42;
    unsigned char* v43;
    uint32_t eax44;
    unsigned char* v45;
    struct s0* rax46;
    struct s0* v47;
    unsigned char* rdi48;
    struct s0* eax49;
    unsigned char* v50;
    uint32_t eax51;
    unsigned char* v52;
    struct s0* rax53;
    struct s0* v54;
    struct s0* rdx55;
    int64_t rdi56;
    struct s0* rax57;
    struct s0* rcx58;
    struct s0* rdx59;
    struct s0* rsi60;
    struct s0* r8_61;
    struct s0* v62;
    struct s0* rax63;
    struct s0* rax64;
    struct s0* v65;

    rbp3 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(__zero_stack_offset()) - 8);
    v4 = reinterpret_cast<struct s0*>(0);
    fun_4009f0(2);
    if (edi <= 5 || edi > 7) {
        rax5 = stderr;
        fun_400a80("main: incorrect number of arguments\n", 1, 36, rax5, r8_6);
        *reinterpret_cast<int32_t*>(&rax7) = 1;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax7) + 4) = 0;
    } else {
        eax8 = pop_init(reinterpret_cast<int64_t>(rbp3) - 32);
        if (eax8) {
            invector_init(reinterpret_cast<int64_t>(rbp3) - 0x410);
            rdx9 = rsi->f40;
            eax10 = invector_load(reinterpret_cast<int64_t>(rbp3) - 0x410, rdx9);
            if (eax10) {
                rdi11 = rsi->f16;
                eax12 = fun_400a30(rdi11, reinterpret_cast<int64_t>(rbp3) - 0x418, 10);
                if (rsi->f16 == v13 || ((eax14 = *v15, !!*reinterpret_cast<signed char*>(&eax14)) || reinterpret_cast<int32_t>(eax12) <= reinterpret_cast<int32_t>(0))) {
                    rax16 = stderr;
                    fun_400a80("invalid integer argument\n", 1, 25, rax16, r8_17);
                    pop_free(v18, 1, 25, v18, 1, 25);
                    *reinterpret_cast<int32_t*>(&rax7) = 1;
                    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax7) + 4) = 0;
                } else {
                    rdi19 = rsi->f8;
                    eax20 = fun_400980(rdi19, "minfn", 6);
                    if (eax20) {
                        rdi21 = rsi->f8;
                        eax22 = fun_400980(rdi21, "pcbmill", 8);
                        if (eax22) {
                            rax23 = stderr;
                            fun_400a80("incorrect 2nd argument\n", 1, 23, rax23, r8_24);
                            *reinterpret_cast<int32_t*>(&rax7) = 1;
                            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax7) + 4) = 0;
                        } else {
                            eax25 = invector_get_num_invector(reinterpret_cast<int64_t>(rbp3) - 0x410, "pcbmill", 8);
                            if (eax25 == eax12) {
                                *reinterpret_cast<int32_t*>(&r8_26) = reinterpret_cast<int32_t>(eval_pcbmill);
                                *reinterpret_cast<int32_t*>(&r8_26 + 1) = 0;
                                pop_set_fns(v27, create_pcbmill_chrom, mutate_pcbmill, crossover_pcbmill, eval_pcbmill);
                                goto addr_400e86_12;
                            } else {
                                rax28 = stderr;
                                fun_400a80("allelesize mismatch with num vectors\n", 1, 37, rax28, r8_29);
                                pop_free(v30, 1, 37, v30, 1, 37);
                                *reinterpret_cast<int32_t*>(&rax7) = 1;
                                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax7) + 4) = 0;
                            }
                        }
                    } else {
                        eax31 = invector_get_width(reinterpret_cast<int64_t>(rbp3) - 0x410, "minfn", 6);
                        if (reinterpret_cast<int32_t>(eax31) - 1 == eax12) {
                            eax32 = invector_get_num_invector(reinterpret_cast<int64_t>(rbp3) - 0x410, "minfn", 6);
                            if (eax32 == 1) {
                                *reinterpret_cast<int32_t*>(&r8_26) = reinterpret_cast<int32_t>(eval_minfn);
                                *reinterpret_cast<int32_t*>(&r8_26 + 1) = 0;
                                pop_set_fns(v33, create_minfn_chrom, mutate_minfn, crossover_minfn, eval_minfn);
                                goto addr_400e86_12;
                            } else {
                                rax34 = stderr;
                                fun_400a80("too many input vectors for minfn data file\n", 1, 43, rax34, r8_35);
                                pop_free(v36, 1, 43, v36, 1, 43);
                                *reinterpret_cast<int32_t*>(&rax7) = 1;
                                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax7) + 4) = 0;
                            }
                        } else {
                            rax37 = stderr;
                            fun_400a80("allelesize mismatch with vector size\n", 1, 37, rax37, r8_38);
                            pop_free(v39, 1, 37, v39, 1, 37);
                            *reinterpret_cast<int32_t*>(&rax7) = 1;
                            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax7) + 4) = 0;
                        }
                    }
                }
            } else {
                pop_free(v40, rdx9, rdx9);
                *reinterpret_cast<int32_t*>(&rax7) = 1;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax7) + 4) = 0;
            }
        } else {
            *reinterpret_cast<int32_t*>(&rax7) = 1;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax7) + 4) = 0;
        }
    }
    addr_401064_21:
    return rax7;
    addr_400e86_12:
    rdi41 = rsi->f24;
    eax42 = fun_400a30(rdi41, reinterpret_cast<int64_t>(rbp3) - 0x418, 10);
    if (rsi->f24 == v43 || ((eax44 = *v45, !!*reinterpret_cast<signed char*>(&eax44)) || reinterpret_cast<int32_t>(eax42) <= reinterpret_cast<int32_t>(1))) {
        rax46 = stderr;
        fun_400a80("invalid integer argument\n", 1, 25, rax46, r8_26);
        pop_free(v47, 1, 25, v47, 1, 25);
        *reinterpret_cast<int32_t*>(&rax7) = 1;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax7) + 4) = 0;
        goto addr_401064_21;
    } else {
        rdi48 = rsi->f32;
        eax49 = fun_400a30(rdi48, reinterpret_cast<int64_t>(rbp3) - 0x418, 10);
        if (rsi->f32 == v50 || ((eax51 = *v52, !!*reinterpret_cast<signed char*>(&eax51)) || reinterpret_cast<int32_t>(eax49) < reinterpret_cast<int32_t>(0))) {
            rax53 = stderr;
            fun_400a80("invalid integer argument\n", 1, 25, rax53, r8_26);
            pop_free(v54, 1, 25, v54, 1, 25);
            *reinterpret_cast<int32_t*>(&rax7) = 1;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax7) + 4) = 0;
            goto addr_401064_21;
        } else {
            if (edi != 7 || (rdx55 = stdout, rdi56 = rsi->f48, rax57 = fun_4009c0(rdi56, "w", rdx55), v4 = rax57, !!v4)) {
                rcx58 = eax49;
                *reinterpret_cast<int32_t*>(&rcx58 + 1) = 0;
                rdx59 = eax12;
                *reinterpret_cast<int32_t*>(&rdx59 + 1) = 0;
                rsi60 = eax42;
                *reinterpret_cast<int32_t*>(&rsi60 + 1) = 0;
                r8_61 = reinterpret_cast<struct s0*>(reinterpret_cast<int64_t>(rbp3) + 0xfffffffffffffbf0);
                rax63 = pop_run(v62, rsi60, rdx59, rcx58, r8_61);
                if (rax63) {
                    pop_free(rax63, rsi60, rdx59, rax63, rsi60, rdx59);
                    if (v4) {
                        fun_4009a0(v4, rsi60, rdx59, rcx58, r8_61);
                    }
                    *reinterpret_cast<int32_t*>(&rax7) = 0;
                    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax7) + 4) = 0;
                    goto addr_401064_21;
                } else {
                    pop_free(rax63, rsi60, rdx59, rax63, rsi60, rdx59);
                    *reinterpret_cast<int32_t*>(&rax7) = 1;
                    *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax7) + 4) = 0;
                    goto addr_401064_21;
                }
            } else {
                rax64 = stderr;
                fun_400a80("Unable to open output file \n", 1, 28, rax64, r8_26);
                pop_free(v65, 1, 28, v65, 1, 28);
                *reinterpret_cast<int32_t*>(&rax7) = 1;
                *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax7) + 4) = 0;
                goto addr_401064_21;
            }
        }
    }
}

void fun_400a86() {
    goto 0x400950;
}

struct s0* create_pcbmill_chrom(struct s0* edi) {
    struct s0* v2;
    struct s0* rdi3;
    struct s0* rax4;
    struct s0* v5;
    struct s0* v6;
    struct s0* v7;
    struct s0* rsi8;
    void* eax9;
    struct s11* v10;
    void* eax11;
    struct s0* rax12;
    struct s0* rax13;
    struct s0* r8_14;

    v2 = edi;
    rdi3 = reinterpret_cast<struct s0*>(reinterpret_cast<uint64_t>(static_cast<int64_t>(reinterpret_cast<int32_t>(v2))) << 2);
    rax4 = fun_400a50(rdi3);
    v5 = rax4;
    if (v5) {
        v6 = reinterpret_cast<struct s0*>(0);
        while (reinterpret_cast<int32_t>(v6) < reinterpret_cast<int32_t>(v2)) {
            *reinterpret_cast<struct s0**>(reinterpret_cast<int32_t>(v6) * 4 + reinterpret_cast<uint32_t>(v5)) = v6;
            v6 = reinterpret_cast<struct s0*>(reinterpret_cast<uint32_t>(v6) + 1);
        }
        v7 = reinterpret_cast<struct s0*>(0);
        while (reinterpret_cast<int32_t>(v7) < reinterpret_cast<int32_t>(v2)) {
            eax9 = fun_400aa0(rdi3, rsi8, rdi3, rsi8);
            __asm__("cdq ");
            v10 = reinterpret_cast<struct s11*>(reinterpret_cast<int32_t>(eax9) % reinterpret_cast<int32_t>(v2));
            eax11 = fun_400aa0(rdi3, rsi8);
            __asm__("cdq ");
            *reinterpret_cast<struct s11**>(&rsi8) = v10;
            *reinterpret_cast<int32_t*>(&rsi8 + 1) = 0;
            rdi3 = v5;
            gene_swap_alleles(rdi3, *reinterpret_cast<struct s11**>(&rsi8), reinterpret_cast<int32_t>(eax11) % reinterpret_cast<int32_t>(v2));
            v7 = reinterpret_cast<struct s0*>(&v10->f1);
        }
        rax12 = v5;
    } else {
        rax13 = stderr;
        fun_400a80("Unable to allocate chromosome memory", 1, 36, rax13, r8_14);
        *reinterpret_cast<int32_t*>(&rax12) = 0;
        *reinterpret_cast<int32_t*>(&rax12 + 1) = 0;
    }
    return rax12;
}

void fun_4009c6() {
    goto 0x400950;
}

void fun_4009a6() {
    goto 0x400950;
}

struct s0* create_minfn_chrom(int32_t edi, struct s0* rsi) {
    int32_t v3;
    struct s0* rdi4;
    struct s0* rax5;
    struct s0* v6;
    int32_t v7;
    void* eax8;
    int64_t rcx9;
    int64_t rdx10;
    uint32_t eax11;
    uint32_t eax12;
    struct s0* rax13;
    struct s0* rax14;
    struct s0* r8_15;

    v3 = edi;
    rdi4 = reinterpret_cast<struct s0*>(reinterpret_cast<uint64_t>(static_cast<int64_t>(v3)) << 2);
    rax5 = fun_400a50(rdi4);
    v6 = rax5;
    if (v6) {
        v7 = 0;
        while (v7 < v3) {
            eax8 = fun_400aa0(rdi4, rsi);
            *reinterpret_cast<void**>(&rcx9) = eax8;
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx9) + 4) = 0;
            *reinterpret_cast<int32_t*>(&rdx10) = __intrinsic();
            *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx10) + 4) = 0;
            eax11 = (static_cast<int32_t>(rdx10 + rcx9) >> 4) - reinterpret_cast<uint32_t>(reinterpret_cast<int32_t>(*reinterpret_cast<void**>(&rcx9)) >> 31);
            eax12 = eax11 + eax11;
            *reinterpret_cast<struct s0**>(v7 * 4 + reinterpret_cast<uint32_t>(v6)) = reinterpret_cast<struct s0*>(reinterpret_cast<int32_t>(*reinterpret_cast<void**>(&rcx9)) - ((eax12 << 4) - eax12));
            ++v7;
        }
        rax13 = v6;
    } else {
        rax14 = stderr;
        fun_400a80("Unable to allocate chromosome memory", 1, 36, rax14, r8_15);
        *reinterpret_cast<int32_t*>(&rax13) = 0;
        *reinterpret_cast<int32_t*>(&rax13 + 1) = 0;
    }
    return rax13;
}

struct s0* mutate_pcbmill(struct s0* rdi, struct s0* rsi, struct s0* rdx, int64_t rcx, struct s0* r8) {
    struct s0* rax6;
    void* eax7;
    struct s11* v8;
    int64_t rax9;
    int32_t v10;
    struct s0* rdi11;
    struct s0* rax12;

    rax6 = gene_copy(rdi, rsi, rdx, rcx, r8);
    if (rax6) {
        eax7 = fun_400aa0(rdi, rsi);
        __asm__("cdq ");
        v8 = reinterpret_cast<struct s11*>(reinterpret_cast<int32_t>(eax7) % reinterpret_cast<int32_t>(rdi->f8));
        *reinterpret_cast<struct s11**>(&rax9) = v8;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rax9) + 4) = 0;
        __asm__("cdq ");
        v10 = static_cast<int32_t>(rax9 + 1) % reinterpret_cast<int32_t>(rdi->f8);
        rdi11 = *reinterpret_cast<struct s0**>(&rax6->f0);
        gene_swap_alleles(rdi11, v8, v10);
        rax12 = rax6;
    } else {
        *reinterpret_cast<int32_t*>(&rax12) = 0;
        *reinterpret_cast<int32_t*>(&rax12 + 1) = 0;
    }
    return rax12;
}

struct s0* mutate_minfn(struct s0* rdi, struct s0* rsi, struct s0* rdx, int64_t rcx, struct s0* r8) {
    struct s0* rax6;
    void* eax7;
    int32_t v8;
    struct s0** rbx9;
    void* eax10;
    int64_t rcx11;
    int64_t rdx12;
    uint32_t eax13;
    uint32_t eax14;
    struct s0* rax15;

    rax6 = gene_copy(rdi, rsi, rdx, rcx, r8);
    if (rax6) {
        eax7 = fun_400aa0(rdi, rsi);
        __asm__("cdq ");
        v8 = reinterpret_cast<int32_t>(eax7) % reinterpret_cast<int32_t>(rax6->f8);
        rbx9 = reinterpret_cast<struct s0**>(reinterpret_cast<uint32_t>(*reinterpret_cast<struct s0**>(&rax6->f0)) + (reinterpret_cast<uint64_t>(static_cast<int64_t>(v8)) << 2));
        eax10 = fun_400aa0(rdi, rsi);
        *reinterpret_cast<void**>(&rcx11) = eax10;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rcx11) + 4) = 0;
        *reinterpret_cast<int32_t*>(&rdx12) = __intrinsic();
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx12) + 4) = 0;
        eax13 = (static_cast<int32_t>(rdx12 + rcx11) >> 4) - reinterpret_cast<uint32_t>(reinterpret_cast<int32_t>(*reinterpret_cast<void**>(&rcx11)) >> 31);
        eax14 = eax13 + eax13;
        *rbx9 = reinterpret_cast<struct s0*>(reinterpret_cast<int32_t>(*reinterpret_cast<void**>(&rcx11)) - ((eax14 << 4) - eax14));
        rax15 = rax6;
    } else {
        *reinterpret_cast<int32_t*>(&rax15) = 0;
        *reinterpret_cast<int32_t*>(&rax15 + 1) = 0;
    }
    return rax15;
}

struct s0* crossover_pcbmill(struct s0* rdi, struct s0* rsi, struct s0* rdx, int64_t rcx, struct s0* r8) {
    struct s0* v6;
    struct s0* v7;
    struct s0* rax8;
    struct s0* v9;
    void* eax10;
    int64_t rdx11;
    int32_t v12;
    void* eax13;
    int32_t v14;
    int32_t v15;
    int32_t v16;
    struct s0* v17;
    struct s0* edx18;
    struct s0* rdi19;
    int32_t eax20;
    struct s0* rax21;

    v6 = rdi;
    v7 = rsi;
    rax8 = gene_copy(v6, rsi, rdx, rcx, r8);
    v9 = rax8;
    if (v9) {
        eax10 = fun_400aa0(v6, rsi);
        *reinterpret_cast<struct s0**>(&rdx11) = v6->f8;
        *reinterpret_cast<int32_t*>(reinterpret_cast<int64_t>(&rdx11) + 4) = 0;
        __asm__("cdq ");
        v12 = reinterpret_cast<int32_t>(eax10) % static_cast<int32_t>(rdx11 - 1);
        eax13 = fun_400aa0(v6, rsi);
        __asm__("cdq ");
        v14 = reinterpret_cast<int32_t>(eax13) % reinterpret_cast<int32_t>(~v12 + reinterpret_cast<uint32_t>(v6->f8)) + 1;
        v15 = v14 + v12;
        v16 = 0;
        while (v15 - v12 >= v16) {
            *reinterpret_cast<struct s0**>((static_cast<int64_t>(v16) << 2) + reinterpret_cast<uint32_t>(*reinterpret_cast<struct s0**>(&v9->f0))) = *reinterpret_cast<struct s0**>(reinterpret_cast<uint32_t>(*reinterpret_cast<struct s0**>(&v6->f0)) + (reinterpret_cast<uint64_t>(static_cast<int64_t>(v12 + v16)) << 2));
            ++v16;
        }
        v17 = reinterpret_cast<struct s0*>(0);
        while (reinterpret_cast<int32_t>(v7->f8) > reinterpret_cast<int32_t>(v17)) {
            edx18 = *reinterpret_cast<struct s0**>(reinterpret_cast<uint32_t>(*reinterpret_cast<struct s0**>(&v7->f0)) + (reinterpret_cast<uint64_t>(static_cast<int64_t>(reinterpret_cast<int32_t>(v17))) << 2));
            rdi19 = *reinterpret_cast<struct s0**>(&v9->f0);
            eax20 = gene_chrom_contains(rdi19, v15 - v12, edx18);
            if (!eax20) {
                *reinterpret_cast<struct s0**>((static_cast<int64_t>(v16) << 2) + reinterpret_cast<uint32_t>(*reinterpret_cast<struct s0**>(&v9->f0))) = *reinterpret_cast<struct s0**>(reinterpret_cast<uint32_t>(*reinterpret_cast<struct s0**>(&v7->f0)) + (reinterpret_cast<uint64_t>(static_cast<int64_t>(reinterpret_cast<int32_t>(v17))) << 2));
                ++v16;
            }
            v17 = reinterpret_cast<struct s0*>(reinterpret_cast<uint32_t>(v17) + 1);
        }
        v9->f24 = reinterpret_cast<struct s0*>(0);
        v9->f16 = reinterpret_cast<struct s0*>(0);
        rax21 = v9;
    } else {
        *reinterpret_cast<int32_t*>(&rax21) = 0;
        *reinterpret_cast<int32_t*>(&rax21 + 1) = 0;
    }
    return rax21;
}

struct s0* crossover_minfn(struct s0* rdi, struct s0* rsi, struct s0* rdx, int64_t rcx, struct s0* r8) {
    struct s0* v6;
    struct s0* v7;
    struct s0* rax8;
    struct s0* v9;
    void* eax10;
    struct s0* v11;
    struct s0* v12;
    struct s0* rax13;

    v6 = rdi;
    v7 = rsi;
    rax8 = gene_copy(v6, rsi, rdx, rcx, r8);
    v9 = rax8;
    if (v9) {
        eax10 = fun_400aa0(v6, rsi);
        __asm__("cdq ");
        v11 = reinterpret_cast<struct s0*>(reinterpret_cast<int32_t>(eax10) % reinterpret_cast<int32_t>(v6->f8));
        v12 = reinterpret_cast<struct s0*>(0);
        while (reinterpret_cast<int32_t>(v12) <= reinterpret_cast<int32_t>(v11)) {
            *reinterpret_cast<struct s0**>((static_cast<int64_t>(reinterpret_cast<int32_t>(v12)) << 2) + reinterpret_cast<uint32_t>(*reinterpret_cast<struct s0**>(&v9->f0))) = *reinterpret_cast<struct s0**>(reinterpret_cast<uint32_t>(*reinterpret_cast<struct s0**>(&v6->f0)) + (reinterpret_cast<uint64_t>(static_cast<int64_t>(reinterpret_cast<int32_t>(v12))) << 2));
            v12 = reinterpret_cast<struct s0*>(reinterpret_cast<uint32_t>(v12) + 1);
        }
        while (reinterpret_cast<int32_t>(v7->f8) > reinterpret_cast<int32_t>(v12)) {
            *reinterpret_cast<struct s0**>((static_cast<int64_t>(reinterpret_cast<int32_t>(v12)) << 2) + reinterpret_cast<uint32_t>(*reinterpret_cast<struct s0**>(&v9->f0))) = *reinterpret_cast<struct s0**>(reinterpret_cast<uint32_t>(*reinterpret_cast<struct s0**>(&v7->f0)) + (reinterpret_cast<uint64_t>(static_cast<int64_t>(reinterpret_cast<int32_t>(v12))) << 2));
            v12 = reinterpret_cast<struct s0*>(reinterpret_cast<uint32_t>(v12) + 1);
        }
        v9->f24 = reinterpret_cast<struct s0*>(0);
        v9->f16 = reinterpret_cast<struct s0*>(0);
        rax13 = v9;
    } else {
        *reinterpret_cast<int32_t*>(&rax13) = 0;
        *reinterpret_cast<int32_t*>(&rax13 + 1) = 0;
    }
    return rax13;
}

struct s13 {
    int32_t f0;
    int32_t* f4;
};

int64_t eval_pcbmill(int32_t* rdi, struct s5* rsi) {
    int32_t* v3;
    int32_t* rax4;
    int32_t* v5;
    struct s5* rdi6;
    int32_t eax7;
    int32_t v8;
    int32_t v9;
    int32_t esi10;
    struct s9* rax11;
    int32_t esi12;
    struct s9* rax13;
    struct s13* rdi14;
    struct s13* rsi15;

    v3 = rdi;
    rax4 = gene_get_chrom(rsi);
    v5 = rax4;
    rdi6 = rsi;
    eax7 = gene_get_num_alleles(rdi6);
    v8 = eax7;
    v9 = 0;
    while (v8 - 1 > v9) {
        esi10 = *reinterpret_cast<int32_t*>(v5 + v9);
        rax11 = invector_get_table_row(v3, esi10);
        esi12 = *reinterpret_cast<int32_t*>(v5 + (v9 + 1));
        rax13 = invector_get_table_row(v3, esi12);
        pcbmill_distance(rax11, rax13);
        rax11->f0 = rax13->f0;
        rdi14 = reinterpret_cast<struct s13*>(&rax11->f4);
        rsi15 = reinterpret_cast<struct s13*>(&rax13->f4);
        __asm__("addsd xmm0, xmm1");
        rdi14->f0 = rsi15->f0;
        rdi6 = reinterpret_cast<struct s5*>(&rdi14->f4);
        rsi = reinterpret_cast<struct s5*>(&rsi15->f4);
        ++v9;
    }
    rdi6->f0 = rsi->f0;
    return 0;
}

void fun_4009d6() {
    goto 0x400950;
}

void fun_400a16() {
    goto 0x400950;
}

void fun_400966() {
    goto 0x400950;
}

struct s14 {
    struct s0* f0;
    signed char[4] pad8;
    struct s14* f8;
};

void pop_display(struct s14** rdi, struct s0* rsi, struct s0* rdx) {
    struct s14* v4;
    struct s0* rdi5;

    v4 = *rdi;
    while (v4) {
        rdi5 = v4->f0;
        gene_print(rdi5, rsi, rdx);
        v4 = v4->f8;
    }
    return;
}

void fun_400996() {
    goto 0x400950;
}

void fun_400a36() {
    goto 0x400950;
}

void fun_400986() {
    goto 0x400950;
}

void fun_400aa6() {
    goto 0x400950;
}

void fun_400a56() {
    goto 0x400950;
}

void fun_400a46() {
    goto 0x400950;
}

void fun_4009b6() {
    goto 0x400950;
}

void fun_400976() {
    goto 0x400950;
}

void fun_400a76() {
    goto 0x400950;
}

void fun_400a06() {
    goto 0x400950;
}

void fun_4009f6() {
    goto 0x400950;
}

void fun_400a96() {
    goto 0x400950;
}

void fun_400a66() {
    goto 0x400950;
}

void _start() {
    void* rsp1;
    int64_t rdx2;
    int64_t rax3;

    rsp1 = reinterpret_cast<void*>(reinterpret_cast<int64_t>(__zero_stack_offset()) + 8);
    fun_4009e0(main, __return_address(), rsp1, __libc_csu_init, __libc_csu_fini, rdx2, (reinterpret_cast<uint64_t>(rsp1) & 0xfffffffffffffff0) - 8 - 8, rax3);
    __asm__("hlt ");
}

void fun_4009e6() {
    goto 0x400950;
}
