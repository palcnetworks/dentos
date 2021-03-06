#ifndef __qsd61_aom_a_48_sfp_plus_cpld_reg_H__
#define __qsd61_aom_a_48_sfp_plus_cpld_reg_H__


static int system_cpld_raw_read(struct device *dev, struct device_attribute *attr, char *buf,
    int reg_offset, int reg_width, int fld_shift, int fld_width, int fld_mask, char *reg_name);
static int system_cpld_raw_write(struct device *dev, struct device_attribute *attr, const char *buf, size_t count,
    int reg_offset, int reg_width, int fld_shift, int fld_width, int fld_mask, char *reg_name);

/* Generic CPLD read function */
#define FLD_RAW_RD_FUNC(_reg, _fld, _wdh) static ssize_t \
system_cpld_##_fld##_raw_read(struct device *dev, struct device_attribute *attr, char *buf) { \
    return system_cpld_raw_read(dev, attr, buf, _reg##_offset, _reg##_width, _fld##_shift, _fld##_width, _fld##_mask, #_reg); \
}

/* Generic CPLD write function */
#define FLD_RAW_WR_FUNC(_reg, _fld, _wdh) static ssize_t \
system_cpld_##_fld##_raw_write(struct device *dev, struct device_attribute *attr, const char *buf, size_t count) { \
    return system_cpld_raw_write(dev, attr, buf, count, _reg##_offset, _reg##_width, _fld##_shift, _fld##_width, _fld##_mask, #_reg); \
}

/* CPLD register definition macros */
#define REG_DEF(_reg, _off, _wdh) \
static unsigned int _reg##_offset = (unsigned int)(_off); \
static unsigned int _reg##_width = (unsigned int)(_wdh);

/* CPLD register field definition macros, with generic read/write function */
#define FLD_RAW_RO_DEF(_reg, _fld, _sft, _wdh) \
static unsigned int _fld##_shift = (unsigned int)(_sft); \
static unsigned int _fld##_width = (unsigned int)(_wdh); \
static unsigned int _fld##_mask = ((((unsigned int)1) << (_wdh)) - 1); \
FLD_RAW_RD_FUNC(_reg, _fld, _wdh)

#define FLD_RAW_RW_DEF(_reg, _fld, _sft, _wdh) \
static unsigned int _fld##_shift = (unsigned int)(_sft); \
static unsigned int _fld##_width = (unsigned int)(_wdh); \
static unsigned int _fld##_mask = ((((unsigned int)1) << (_wdh)) - 1); \
FLD_RAW_RD_FUNC(_reg, _fld, _wdh) FLD_RAW_WR_FUNC(_reg, _fld, _wdh)


/* Declare system CPLD registers */
/*           register name                          offset  width */
/*           --------------------------------      -------  ----- */
REG_DEF(     reset_n_interrupt_reg  ,                 0x01,   8)
REG_DEF(     module_absence_a_reg   ,                 0x02,   8)
REG_DEF(     module_absence_b_reg   ,                 0x03,   8)
REG_DEF(     module_absence_c_reg   ,                 0x04,   8)
REG_DEF(     module_absence_d_reg   ,                 0x05,   8)
REG_DEF(     module_absence_e_reg   ,                 0x06,   8)
REG_DEF(     module_absence_f_reg   ,                 0x07,   8)
REG_DEF(     receiver_loss_a_reg    ,                 0x08,   8)
REG_DEF(     receiver_loss_b_reg    ,                 0x09,   8)
REG_DEF(     receiver_loss_c_reg    ,                 0x0a,   8)
REG_DEF(     receiver_loss_d_reg    ,                 0x0b,   8)
REG_DEF(     receiver_loss_e_reg    ,                 0x0c,   8)
REG_DEF(     receiver_loss_f_reg    ,                 0x0d,   8)
REG_DEF(     transmitter_fault_a_reg,                 0x0e,   8)
REG_DEF(     transmitter_fault_b_reg,                 0x0f,   8)
REG_DEF(     transmitter_fault_c_reg,                 0x10,   8)
REG_DEF(     transmitter_fault_d_reg,                 0x11,   8)
REG_DEF(     transmitter_fault_e_reg,                 0x12,   8)
REG_DEF(     transmitter_fault_f_reg,                 0x13,   8)
REG_DEF(     transmitter_disable_a_reg,                 0x14,   8)
REG_DEF(     transmitter_disable_b_reg,                 0x15,   8)
REG_DEF(     transmitter_disable_c_reg,                 0x16,   8)
REG_DEF(     transmitter_disable_d_reg,                 0x17,   8)
REG_DEF(     transmitter_disable_e_reg,                 0x18,   8)
REG_DEF(     transmitter_disable_f_reg,                 0x19,   8)
REG_DEF(     reset_n_interrupt_mask_reg,                 0x20,   8)
REG_DEF(     module_absence_a_mask_reg,                 0x21,   8)
REG_DEF(     module_absence_b_mask_reg,                 0x22,   8)
REG_DEF(     module_absence_c_mask_reg,                 0x23,   8)
REG_DEF(     module_absence_d_mask_reg,                 0x24,   8)
REG_DEF(     module_absence_e_mask_reg,                 0x25,   8)
REG_DEF(     module_absence_f_mask_reg,                 0x26,   8)
REG_DEF(     module_absence_a_proc_reg,                 0x80,   8)
REG_DEF(     module_absence_b_proc_reg,                 0x81,   8)
REG_DEF(     module_absence_c_proc_reg,                 0x82,   8)
REG_DEF(     module_absence_d_proc_reg,                 0x83,   8)
REG_DEF(     module_absence_e_proc_reg,                 0x84,   8)
REG_DEF(     module_absence_f_proc_reg,                 0x85,   8)
REG_DEF(     cpld_version_reg       ,                 0xfd,   8)


/* Declare system CPLD register's fields */
/*                      register name               field name                  shift  width */
/*                      ----------------------      ----------------            ------ ----- */
FLD_RAW_RW_DEF(         reset_n_interrupt_reg,      cpld2_irq,                  5,      1)
FLD_RAW_RO_DEF(         reset_n_interrupt_reg,      cpld2_int_n,                1,      1)
FLD_RAW_RO_DEF(         module_absence_a_reg,       p08_mod_abs,                7,      1)
FLD_RAW_RO_DEF(         module_absence_a_reg,       p07_mod_abs,                6,      1)
FLD_RAW_RO_DEF(         module_absence_a_reg,       p06_mod_abs,                5,      1)
FLD_RAW_RO_DEF(         module_absence_a_reg,       p05_mod_abs,                4,      1)
FLD_RAW_RO_DEF(         module_absence_a_reg,       p04_mod_abs,                3,      1)
FLD_RAW_RO_DEF(         module_absence_a_reg,       p03_mod_abs,                2,      1)
FLD_RAW_RO_DEF(         module_absence_a_reg,       p02_mod_abs,                1,      1)
FLD_RAW_RO_DEF(         module_absence_a_reg,       p01_mod_abs,                0,      1)
FLD_RAW_RO_DEF(         module_absence_b_reg,       p16_mod_abs,                7,      1)
FLD_RAW_RO_DEF(         module_absence_b_reg,       p15_mod_abs,                6,      1)
FLD_RAW_RO_DEF(         module_absence_b_reg,       p14_mod_abs,                5,      1)
FLD_RAW_RO_DEF(         module_absence_b_reg,       p13_mod_abs,                4,      1)
FLD_RAW_RO_DEF(         module_absence_b_reg,       p12_mod_abs,                3,      1)
FLD_RAW_RO_DEF(         module_absence_b_reg,       p11_mod_abs,                2,      1)
FLD_RAW_RO_DEF(         module_absence_b_reg,       p10_mod_abs,                1,      1)
FLD_RAW_RO_DEF(         module_absence_b_reg,       p09_mod_abs,                0,      1)
FLD_RAW_RO_DEF(         module_absence_c_reg,       p24_mod_abs,                7,      1)
FLD_RAW_RO_DEF(         module_absence_c_reg,       p23_mod_abs,                6,      1)
FLD_RAW_RO_DEF(         module_absence_c_reg,       p22_mod_abs,                5,      1)
FLD_RAW_RO_DEF(         module_absence_c_reg,       p21_mod_abs,                4,      1)
FLD_RAW_RO_DEF(         module_absence_c_reg,       p20_mod_abs,                3,      1)
FLD_RAW_RO_DEF(         module_absence_c_reg,       p19_mod_abs,                2,      1)
FLD_RAW_RO_DEF(         module_absence_c_reg,       p18_mod_abs,                1,      1)
FLD_RAW_RO_DEF(         module_absence_c_reg,       p17_mod_abs,                0,      1)
FLD_RAW_RO_DEF(         module_absence_d_reg,       p32_mod_abs,                7,      1)
FLD_RAW_RO_DEF(         module_absence_d_reg,       p31_mod_abs,                6,      1)
FLD_RAW_RO_DEF(         module_absence_d_reg,       p30_mod_abs,                5,      1)
FLD_RAW_RO_DEF(         module_absence_d_reg,       p29_mod_abs,                4,      1)
FLD_RAW_RO_DEF(         module_absence_d_reg,       p28_mod_abs,                3,      1)
FLD_RAW_RO_DEF(         module_absence_d_reg,       p27_mod_abs,                2,      1)
FLD_RAW_RO_DEF(         module_absence_d_reg,       p26_mod_abs,                1,      1)
FLD_RAW_RO_DEF(         module_absence_d_reg,       p25_mod_abs,                0,      1)
FLD_RAW_RO_DEF(         module_absence_e_reg,       p40_mod_abs,                7,      1)
FLD_RAW_RO_DEF(         module_absence_e_reg,       p39_mod_abs,                6,      1)
FLD_RAW_RO_DEF(         module_absence_e_reg,       p38_mod_abs,                5,      1)
FLD_RAW_RO_DEF(         module_absence_e_reg,       p37_mod_abs,                4,      1)
FLD_RAW_RO_DEF(         module_absence_e_reg,       p36_mod_abs,                3,      1)
FLD_RAW_RO_DEF(         module_absence_e_reg,       p35_mod_abs,                2,      1)
FLD_RAW_RO_DEF(         module_absence_e_reg,       p34_mod_abs,                1,      1)
FLD_RAW_RO_DEF(         module_absence_e_reg,       p33_mod_abs,                0,      1)
FLD_RAW_RO_DEF(         module_absence_f_reg,       p48_mod_abs,                7,      1)
FLD_RAW_RO_DEF(         module_absence_f_reg,       p47_mod_abs,                6,      1)
FLD_RAW_RO_DEF(         module_absence_f_reg,       p46_mod_abs,                5,      1)
FLD_RAW_RO_DEF(         module_absence_f_reg,       p45_mod_abs,                4,      1)
FLD_RAW_RO_DEF(         module_absence_f_reg,       p44_mod_abs,                3,      1)
FLD_RAW_RO_DEF(         module_absence_f_reg,       p43_mod_abs,                2,      1)
FLD_RAW_RO_DEF(         module_absence_f_reg,       p42_mod_abs,                1,      1)
FLD_RAW_RO_DEF(         module_absence_f_reg,       p41_mod_abs,                0,      1)
FLD_RAW_RO_DEF(         receiver_loss_a_reg,        p08_rx_los,                 7,      1)
FLD_RAW_RO_DEF(         receiver_loss_a_reg,        p07_rx_los,                 6,      1)
FLD_RAW_RO_DEF(         receiver_loss_a_reg,        p06_rx_los,                 5,      1)
FLD_RAW_RO_DEF(         receiver_loss_a_reg,        p05_rx_los,                 4,      1)
FLD_RAW_RO_DEF(         receiver_loss_a_reg,        p04_rx_los,                 3,      1)
FLD_RAW_RO_DEF(         receiver_loss_a_reg,        p03_rx_los,                 2,      1)
FLD_RAW_RO_DEF(         receiver_loss_a_reg,        p02_rx_los,                 1,      1)
FLD_RAW_RO_DEF(         receiver_loss_a_reg,        p01_rx_los,                 0,      1)
FLD_RAW_RO_DEF(         receiver_loss_b_reg,        p16_rx_los,                 7,      1)
FLD_RAW_RO_DEF(         receiver_loss_b_reg,        p15_rx_los,                 6,      1)
FLD_RAW_RO_DEF(         receiver_loss_b_reg,        p14_rx_los,                 5,      1)
FLD_RAW_RO_DEF(         receiver_loss_b_reg,        p13_rx_los,                 4,      1)
FLD_RAW_RO_DEF(         receiver_loss_b_reg,        p12_rx_los,                 3,      1)
FLD_RAW_RO_DEF(         receiver_loss_b_reg,        p11_rx_los,                 2,      1)
FLD_RAW_RO_DEF(         receiver_loss_b_reg,        p10_rx_los,                 1,      1)
FLD_RAW_RO_DEF(         receiver_loss_b_reg,        p09_rx_los,                 0,      1)
FLD_RAW_RO_DEF(         receiver_loss_c_reg,        p24_rx_los,                 7,      1)
FLD_RAW_RO_DEF(         receiver_loss_c_reg,        p23_rx_los,                 6,      1)
FLD_RAW_RO_DEF(         receiver_loss_c_reg,        p22_rx_los,                 5,      1)
FLD_RAW_RO_DEF(         receiver_loss_c_reg,        p21_rx_los,                 4,      1)
FLD_RAW_RO_DEF(         receiver_loss_c_reg,        p20_rx_los,                 3,      1)
FLD_RAW_RO_DEF(         receiver_loss_c_reg,        p19_rx_los,                 2,      1)
FLD_RAW_RO_DEF(         receiver_loss_c_reg,        p18_rx_los,                 1,      1)
FLD_RAW_RO_DEF(         receiver_loss_c_reg,        p17_rx_los,                 0,      1)
FLD_RAW_RO_DEF(         receiver_loss_d_reg,        p32_rx_los,                 7,      1)
FLD_RAW_RO_DEF(         receiver_loss_d_reg,        p31_rx_los,                 6,      1)
FLD_RAW_RO_DEF(         receiver_loss_d_reg,        p30_rx_los,                 5,      1)
FLD_RAW_RO_DEF(         receiver_loss_d_reg,        p29_rx_los,                 4,      1)
FLD_RAW_RO_DEF(         receiver_loss_d_reg,        p28_rx_los,                 3,      1)
FLD_RAW_RO_DEF(         receiver_loss_d_reg,        p27_rx_los,                 2,      1)
FLD_RAW_RO_DEF(         receiver_loss_d_reg,        p26_rx_los,                 1,      1)
FLD_RAW_RO_DEF(         receiver_loss_d_reg,        p25_rx_los,                 0,      1)
FLD_RAW_RO_DEF(         receiver_loss_e_reg,        p40_rx_los,                 7,      1)
FLD_RAW_RO_DEF(         receiver_loss_e_reg,        p39_rx_los,                 6,      1)
FLD_RAW_RO_DEF(         receiver_loss_e_reg,        p38_rx_los,                 5,      1)
FLD_RAW_RO_DEF(         receiver_loss_e_reg,        p37_rx_los,                 4,      1)
FLD_RAW_RO_DEF(         receiver_loss_e_reg,        p36_rx_los,                 3,      1)
FLD_RAW_RO_DEF(         receiver_loss_e_reg,        p35_rx_los,                 2,      1)
FLD_RAW_RO_DEF(         receiver_loss_e_reg,        p34_rx_los,                 1,      1)
FLD_RAW_RO_DEF(         receiver_loss_e_reg,        p33_rx_los,                 0,      1)
FLD_RAW_RO_DEF(         receiver_loss_f_reg,        p48_rx_los,                 7,      1)
FLD_RAW_RO_DEF(         receiver_loss_f_reg,        p47_rx_los,                 6,      1)
FLD_RAW_RO_DEF(         receiver_loss_f_reg,        p46_rx_los,                 5,      1)
FLD_RAW_RO_DEF(         receiver_loss_f_reg,        p45_rx_los,                 4,      1)
FLD_RAW_RO_DEF(         receiver_loss_f_reg,        p44_rx_los,                 3,      1)
FLD_RAW_RO_DEF(         receiver_loss_f_reg,        p43_rx_los,                 2,      1)
FLD_RAW_RO_DEF(         receiver_loss_f_reg,        p42_rx_los,                 1,      1)
FLD_RAW_RO_DEF(         receiver_loss_f_reg,        p41_rx_los,                 0,      1)
FLD_RAW_RO_DEF(         transmitter_fault_a_reg,    p08_tx_fault,               7,      1)
FLD_RAW_RO_DEF(         transmitter_fault_a_reg,    p07_tx_fault,               6,      1)
FLD_RAW_RO_DEF(         transmitter_fault_a_reg,    p06_tx_fault,               5,      1)
FLD_RAW_RO_DEF(         transmitter_fault_a_reg,    p05_tx_fault,               4,      1)
FLD_RAW_RO_DEF(         transmitter_fault_a_reg,    p04_tx_fault,               3,      1)
FLD_RAW_RO_DEF(         transmitter_fault_a_reg,    p03_tx_fault,               2,      1)
FLD_RAW_RO_DEF(         transmitter_fault_a_reg,    p02_tx_fault,               1,      1)
FLD_RAW_RO_DEF(         transmitter_fault_a_reg,    p01_tx_fault,               0,      1)
FLD_RAW_RO_DEF(         transmitter_fault_b_reg,    p16_tx_fault,               7,      1)
FLD_RAW_RO_DEF(         transmitter_fault_b_reg,    p15_tx_fault,               6,      1)
FLD_RAW_RO_DEF(         transmitter_fault_b_reg,    p14_tx_fault,               5,      1)
FLD_RAW_RO_DEF(         transmitter_fault_b_reg,    p13_tx_fault,               4,      1)
FLD_RAW_RO_DEF(         transmitter_fault_b_reg,    p12_tx_fault,               3,      1)
FLD_RAW_RO_DEF(         transmitter_fault_b_reg,    p11_tx_fault,               2,      1)
FLD_RAW_RO_DEF(         transmitter_fault_b_reg,    p10_tx_fault,               1,      1)
FLD_RAW_RO_DEF(         transmitter_fault_b_reg,    p09_tx_fault,               0,      1)
FLD_RAW_RO_DEF(         transmitter_fault_c_reg,    p24_tx_fault,               7,      1)
FLD_RAW_RO_DEF(         transmitter_fault_c_reg,    p23_tx_fault,               6,      1)
FLD_RAW_RO_DEF(         transmitter_fault_c_reg,    p22_tx_fault,               5,      1)
FLD_RAW_RO_DEF(         transmitter_fault_c_reg,    p21_tx_fault,               4,      1)
FLD_RAW_RO_DEF(         transmitter_fault_c_reg,    p20_tx_fault,               3,      1)
FLD_RAW_RO_DEF(         transmitter_fault_c_reg,    p19_tx_fault,               2,      1)
FLD_RAW_RO_DEF(         transmitter_fault_c_reg,    p18_tx_fault,               1,      1)
FLD_RAW_RO_DEF(         transmitter_fault_c_reg,    p17_tx_fault,               0,      1)
FLD_RAW_RO_DEF(         transmitter_fault_d_reg,    p32_tx_fault,               7,      1)
FLD_RAW_RO_DEF(         transmitter_fault_d_reg,    p31_tx_fault,               6,      1)
FLD_RAW_RO_DEF(         transmitter_fault_d_reg,    p30_tx_fault,               5,      1)
FLD_RAW_RO_DEF(         transmitter_fault_d_reg,    p29_tx_fault,               4,      1)
FLD_RAW_RO_DEF(         transmitter_fault_d_reg,    p28_tx_fault,               3,      1)
FLD_RAW_RO_DEF(         transmitter_fault_d_reg,    p27_tx_fault,               2,      1)
FLD_RAW_RO_DEF(         transmitter_fault_d_reg,    p26_tx_fault,               1,      1)
FLD_RAW_RO_DEF(         transmitter_fault_d_reg,    p25_tx_fault,               0,      1)
FLD_RAW_RO_DEF(         transmitter_fault_e_reg,    p40_tx_fault,               7,      1)
FLD_RAW_RO_DEF(         transmitter_fault_e_reg,    p39_tx_fault,               6,      1)
FLD_RAW_RO_DEF(         transmitter_fault_e_reg,    p38_tx_fault,               5,      1)
FLD_RAW_RO_DEF(         transmitter_fault_e_reg,    p37_tx_fault,               4,      1)
FLD_RAW_RO_DEF(         transmitter_fault_e_reg,    p36_tx_fault,               3,      1)
FLD_RAW_RO_DEF(         transmitter_fault_e_reg,    p35_tx_fault,               2,      1)
FLD_RAW_RO_DEF(         transmitter_fault_e_reg,    p34_tx_fault,               1,      1)
FLD_RAW_RO_DEF(         transmitter_fault_e_reg,    p33_tx_fault,               0,      1)
FLD_RAW_RO_DEF(         transmitter_fault_f_reg,    p48_tx_fault,               7,      1)
FLD_RAW_RO_DEF(         transmitter_fault_f_reg,    p47_tx_fault,               6,      1)
FLD_RAW_RO_DEF(         transmitter_fault_f_reg,    p46_tx_fault,               5,      1)
FLD_RAW_RO_DEF(         transmitter_fault_f_reg,    p45_tx_fault,               4,      1)
FLD_RAW_RO_DEF(         transmitter_fault_f_reg,    p44_tx_fault,               3,      1)
FLD_RAW_RO_DEF(         transmitter_fault_f_reg,    p43_tx_fault,               2,      1)
FLD_RAW_RO_DEF(         transmitter_fault_f_reg,    p42_tx_fault,               1,      1)
FLD_RAW_RO_DEF(         transmitter_fault_f_reg,    p41_tx_fault,               0,      1)
FLD_RAW_RW_DEF(         transmitter_disable_a_reg,  p08_tx_disable,             7,      1)
FLD_RAW_RW_DEF(         transmitter_disable_a_reg,  p07_tx_disable,             6,      1)
FLD_RAW_RW_DEF(         transmitter_disable_a_reg,  p06_tx_disable,             5,      1)
FLD_RAW_RW_DEF(         transmitter_disable_a_reg,  p05_tx_disable,             4,      1)
FLD_RAW_RW_DEF(         transmitter_disable_a_reg,  p04_tx_disable,             3,      1)
FLD_RAW_RW_DEF(         transmitter_disable_a_reg,  p03_tx_disable,             2,      1)
FLD_RAW_RW_DEF(         transmitter_disable_a_reg,  p02_tx_disable,             1,      1)
FLD_RAW_RW_DEF(         transmitter_disable_a_reg,  p01_tx_disable,             0,      1)
FLD_RAW_RW_DEF(         transmitter_disable_b_reg,  p16_tx_disable,             7,      1)
FLD_RAW_RW_DEF(         transmitter_disable_b_reg,  p15_tx_disable,             6,      1)
FLD_RAW_RW_DEF(         transmitter_disable_b_reg,  p14_tx_disable,             5,      1)
FLD_RAW_RW_DEF(         transmitter_disable_b_reg,  p13_tx_disable,             4,      1)
FLD_RAW_RW_DEF(         transmitter_disable_b_reg,  p12_tx_disable,             3,      1)
FLD_RAW_RW_DEF(         transmitter_disable_b_reg,  p11_tx_disable,             2,      1)
FLD_RAW_RW_DEF(         transmitter_disable_b_reg,  p10_tx_disable,             1,      1)
FLD_RAW_RW_DEF(         transmitter_disable_b_reg,  p09_tx_disable,             0,      1)
FLD_RAW_RW_DEF(         transmitter_disable_c_reg,  p24_tx_disable,             7,      1)
FLD_RAW_RW_DEF(         transmitter_disable_c_reg,  p23_tx_disable,             6,      1)
FLD_RAW_RW_DEF(         transmitter_disable_c_reg,  p22_tx_disable,             5,      1)
FLD_RAW_RW_DEF(         transmitter_disable_c_reg,  p21_tx_disable,             4,      1)
FLD_RAW_RW_DEF(         transmitter_disable_c_reg,  p20_tx_disable,             3,      1)
FLD_RAW_RW_DEF(         transmitter_disable_c_reg,  p19_tx_disable,             2,      1)
FLD_RAW_RW_DEF(         transmitter_disable_c_reg,  p18_tx_disable,             1,      1)
FLD_RAW_RW_DEF(         transmitter_disable_c_reg,  p17_tx_disable,             0,      1)
FLD_RAW_RW_DEF(         transmitter_disable_d_reg,  p32_tx_disable,             7,      1)
FLD_RAW_RW_DEF(         transmitter_disable_d_reg,  p31_tx_disable,             6,      1)
FLD_RAW_RW_DEF(         transmitter_disable_d_reg,  p30_tx_disable,             5,      1)
FLD_RAW_RW_DEF(         transmitter_disable_d_reg,  p29_tx_disable,             4,      1)
FLD_RAW_RW_DEF(         transmitter_disable_d_reg,  p28_tx_disable,             3,      1)
FLD_RAW_RW_DEF(         transmitter_disable_d_reg,  p27_tx_disable,             2,      1)
FLD_RAW_RW_DEF(         transmitter_disable_d_reg,  p26_tx_disable,             1,      1)
FLD_RAW_RW_DEF(         transmitter_disable_d_reg,  p25_tx_disable,             0,      1)
FLD_RAW_RW_DEF(         transmitter_disable_e_reg,  p40_tx_disable,             7,      1)
FLD_RAW_RW_DEF(         transmitter_disable_e_reg,  p39_tx_disable,             6,      1)
FLD_RAW_RW_DEF(         transmitter_disable_e_reg,  p38_tx_disable,             5,      1)
FLD_RAW_RW_DEF(         transmitter_disable_e_reg,  p37_tx_disable,             4,      1)
FLD_RAW_RW_DEF(         transmitter_disable_e_reg,  p36_tx_disable,             3,      1)
FLD_RAW_RW_DEF(         transmitter_disable_e_reg,  p35_tx_disable,             2,      1)
FLD_RAW_RW_DEF(         transmitter_disable_e_reg,  p34_tx_disable,             1,      1)
FLD_RAW_RW_DEF(         transmitter_disable_e_reg,  p33_tx_disable,             0,      1)
FLD_RAW_RW_DEF(         transmitter_disable_f_reg,  p48_tx_disable,             7,      1)
FLD_RAW_RW_DEF(         transmitter_disable_f_reg,  p47_tx_disable,             6,      1)
FLD_RAW_RW_DEF(         transmitter_disable_f_reg,  p46_tx_disable,             5,      1)
FLD_RAW_RW_DEF(         transmitter_disable_f_reg,  p45_tx_disable,             4,      1)
FLD_RAW_RW_DEF(         transmitter_disable_f_reg,  p44_tx_disable,             3,      1)
FLD_RAW_RW_DEF(         transmitter_disable_f_reg,  p43_tx_disable,             2,      1)
FLD_RAW_RW_DEF(         transmitter_disable_f_reg,  p42_tx_disable,             1,      1)
FLD_RAW_RW_DEF(         transmitter_disable_f_reg,  p41_tx_disable,             0,      1)
FLD_RAW_RW_DEF(         reset_n_interrupt_mask_reg, cpld2_irq_msk,              5,      1)
FLD_RAW_RW_DEF(         reset_n_interrupt_mask_reg, cpld2_int_n_msk,            1,      1)
FLD_RAW_RW_DEF(         module_absence_a_mask_reg,  p08_mod_abs_msk,            7,      1)
FLD_RAW_RW_DEF(         module_absence_a_mask_reg,  p07_mod_abs_msk,            6,      1)
FLD_RAW_RW_DEF(         module_absence_a_mask_reg,  p06_mod_abs_msk,            5,      1)
FLD_RAW_RW_DEF(         module_absence_a_mask_reg,  p05_mod_abs_msk,            4,      1)
FLD_RAW_RW_DEF(         module_absence_a_mask_reg,  p04_mod_abs_msk,            3,      1)
FLD_RAW_RW_DEF(         module_absence_a_mask_reg,  p03_mod_abs_msk,            2,      1)
FLD_RAW_RW_DEF(         module_absence_a_mask_reg,  p02_mod_abs_msk,            1,      1)
FLD_RAW_RW_DEF(         module_absence_a_mask_reg,  p01_mod_abs_msk,            0,      1)
FLD_RAW_RW_DEF(         module_absence_b_mask_reg,  p16_mod_abs_msk,            7,      1)
FLD_RAW_RW_DEF(         module_absence_b_mask_reg,  p15_mod_abs_msk,            6,      1)
FLD_RAW_RW_DEF(         module_absence_b_mask_reg,  p14_mod_abs_msk,            5,      1)
FLD_RAW_RW_DEF(         module_absence_b_mask_reg,  p13_mod_abs_msk,            4,      1)
FLD_RAW_RW_DEF(         module_absence_b_mask_reg,  p12_mod_abs_msk,            3,      1)
FLD_RAW_RW_DEF(         module_absence_b_mask_reg,  p11_mod_abs_msk,            2,      1)
FLD_RAW_RW_DEF(         module_absence_b_mask_reg,  p10_mod_abs_msk,            1,      1)
FLD_RAW_RW_DEF(         module_absence_b_mask_reg,  p09_mod_abs_msk,            0,      1)
FLD_RAW_RW_DEF(         module_absence_c_mask_reg,  p24_mod_abs_msk,            7,      1)
FLD_RAW_RW_DEF(         module_absence_c_mask_reg,  p23_mod_abs_msk,            6,      1)
FLD_RAW_RW_DEF(         module_absence_c_mask_reg,  p22_mod_abs_msk,            5,      1)
FLD_RAW_RW_DEF(         module_absence_c_mask_reg,  p21_mod_abs_msk,            4,      1)
FLD_RAW_RW_DEF(         module_absence_c_mask_reg,  p20_mod_abs_msk,            3,      1)
FLD_RAW_RW_DEF(         module_absence_c_mask_reg,  p19_mod_abs_msk,            2,      1)
FLD_RAW_RW_DEF(         module_absence_c_mask_reg,  p18_mod_abs_msk,            1,      1)
FLD_RAW_RW_DEF(         module_absence_c_mask_reg,  p17_mod_abs_msk,            0,      1)
FLD_RAW_RW_DEF(         module_absence_d_mask_reg,  p32_mod_abs_msk,            7,      1)
FLD_RAW_RW_DEF(         module_absence_d_mask_reg,  p31_mod_abs_msk,            6,      1)
FLD_RAW_RW_DEF(         module_absence_d_mask_reg,  p30_mod_abs_msk,            5,      1)
FLD_RAW_RW_DEF(         module_absence_d_mask_reg,  p29_mod_abs_msk,            4,      1)
FLD_RAW_RW_DEF(         module_absence_d_mask_reg,  p28_mod_abs_msk,            3,      1)
FLD_RAW_RW_DEF(         module_absence_d_mask_reg,  p27_mod_abs_msk,            2,      1)
FLD_RAW_RW_DEF(         module_absence_d_mask_reg,  p26_mod_abs_msk,            1,      1)
FLD_RAW_RW_DEF(         module_absence_d_mask_reg,  p25_mod_abs_msk,            0,      1)
FLD_RAW_RW_DEF(         module_absence_e_mask_reg,  p40_mod_abs_msk,            7,      1)
FLD_RAW_RW_DEF(         module_absence_e_mask_reg,  p39_mod_abs_msk,            6,      1)
FLD_RAW_RW_DEF(         module_absence_e_mask_reg,  p38_mod_abs_msk,            5,      1)
FLD_RAW_RW_DEF(         module_absence_e_mask_reg,  p37_mod_abs_msk,            4,      1)
FLD_RAW_RW_DEF(         module_absence_e_mask_reg,  p36_mod_abs_msk,            3,      1)
FLD_RAW_RW_DEF(         module_absence_e_mask_reg,  p35_mod_abs_msk,            2,      1)
FLD_RAW_RW_DEF(         module_absence_e_mask_reg,  p34_mod_abs_msk,            1,      1)
FLD_RAW_RW_DEF(         module_absence_e_mask_reg,  p33_mod_abs_msk,            0,      1)
FLD_RAW_RW_DEF(         module_absence_f_mask_reg,  p48_mod_abs_msk,            7,      1)
FLD_RAW_RW_DEF(         module_absence_f_mask_reg,  p47_mod_abs_msk,            6,      1)
FLD_RAW_RW_DEF(         module_absence_f_mask_reg,  p46_mod_abs_msk,            5,      1)
FLD_RAW_RW_DEF(         module_absence_f_mask_reg,  p45_mod_abs_msk,            4,      1)
FLD_RAW_RW_DEF(         module_absence_f_mask_reg,  p44_mod_abs_msk,            3,      1)
FLD_RAW_RW_DEF(         module_absence_f_mask_reg,  p43_mod_abs_msk,            2,      1)
FLD_RAW_RW_DEF(         module_absence_f_mask_reg,  p42_mod_abs_msk,            1,      1)
FLD_RAW_RW_DEF(         module_absence_f_mask_reg,  p41_mod_abs_msk,            0,      1)
FLD_RAW_RW_DEF(         module_absence_a_proc_reg,  p08_mod_abs_proc,           7,      1)
FLD_RAW_RW_DEF(         module_absence_a_proc_reg,  p07_mod_abs_proc,           6,      1)
FLD_RAW_RW_DEF(         module_absence_a_proc_reg,  p06_mod_abs_proc,           5,      1)
FLD_RAW_RW_DEF(         module_absence_a_proc_reg,  p05_mod_abs_proc,           4,      1)
FLD_RAW_RW_DEF(         module_absence_a_proc_reg,  p04_mod_abs_proc,           3,      1)
FLD_RAW_RW_DEF(         module_absence_a_proc_reg,  p03_mod_abs_proc,           2,      1)
FLD_RAW_RW_DEF(         module_absence_a_proc_reg,  p02_mod_abs_proc,           1,      1)
FLD_RAW_RW_DEF(         module_absence_a_proc_reg,  p01_mod_abs_proc,           0,      1)
FLD_RAW_RW_DEF(         module_absence_b_proc_reg,  p16_mod_abs_proc,           7,      1)
FLD_RAW_RW_DEF(         module_absence_b_proc_reg,  p15_mod_abs_proc,           6,      1)
FLD_RAW_RW_DEF(         module_absence_b_proc_reg,  p14_mod_abs_proc,           5,      1)
FLD_RAW_RW_DEF(         module_absence_b_proc_reg,  p13_mod_abs_proc,           4,      1)
FLD_RAW_RW_DEF(         module_absence_b_proc_reg,  p12_mod_abs_proc,           3,      1)
FLD_RAW_RW_DEF(         module_absence_b_proc_reg,  p11_mod_abs_proc,           2,      1)
FLD_RAW_RW_DEF(         module_absence_b_proc_reg,  p10_mod_abs_proc,           1,      1)
FLD_RAW_RW_DEF(         module_absence_b_proc_reg,  p09_mod_abs_proc,           0,      1)
FLD_RAW_RW_DEF(         module_absence_c_proc_reg,  p24_mod_abs_proc,           7,      1)
FLD_RAW_RW_DEF(         module_absence_c_proc_reg,  p23_mod_abs_proc,           6,      1)
FLD_RAW_RW_DEF(         module_absence_c_proc_reg,  p22_mod_abs_proc,           5,      1)
FLD_RAW_RW_DEF(         module_absence_c_proc_reg,  p21_mod_abs_proc,           4,      1)
FLD_RAW_RW_DEF(         module_absence_c_proc_reg,  p20_mod_abs_proc,           3,      1)
FLD_RAW_RW_DEF(         module_absence_c_proc_reg,  p19_mod_abs_proc,           2,      1)
FLD_RAW_RW_DEF(         module_absence_c_proc_reg,  p18_mod_abs_proc,           1,      1)
FLD_RAW_RW_DEF(         module_absence_c_proc_reg,  p17_mod_abs_proc,           0,      1)
FLD_RAW_RW_DEF(         module_absence_d_proc_reg,  p32_mod_abs_proc,           7,      1)
FLD_RAW_RW_DEF(         module_absence_d_proc_reg,  p31_mod_abs_proc,           6,      1)
FLD_RAW_RW_DEF(         module_absence_d_proc_reg,  p30_mod_abs_proc,           5,      1)
FLD_RAW_RW_DEF(         module_absence_d_proc_reg,  p29_mod_abs_proc,           4,      1)
FLD_RAW_RW_DEF(         module_absence_d_proc_reg,  p28_mod_abs_proc,           3,      1)
FLD_RAW_RW_DEF(         module_absence_d_proc_reg,  p27_mod_abs_proc,           2,      1)
FLD_RAW_RW_DEF(         module_absence_d_proc_reg,  p26_mod_abs_proc,           1,      1)
FLD_RAW_RW_DEF(         module_absence_d_proc_reg,  p25_mod_abs_proc,           0,      1)
FLD_RAW_RW_DEF(         module_absence_e_proc_reg,  p40_mod_abs_proc,           7,      1)
FLD_RAW_RW_DEF(         module_absence_e_proc_reg,  p39_mod_abs_proc,           6,      1)
FLD_RAW_RW_DEF(         module_absence_e_proc_reg,  p38_mod_abs_proc,           5,      1)
FLD_RAW_RW_DEF(         module_absence_e_proc_reg,  p37_mod_abs_proc,           4,      1)
FLD_RAW_RW_DEF(         module_absence_e_proc_reg,  p36_mod_abs_proc,           3,      1)
FLD_RAW_RW_DEF(         module_absence_e_proc_reg,  p35_mod_abs_proc,           2,      1)
FLD_RAW_RW_DEF(         module_absence_e_proc_reg,  p34_mod_abs_proc,           1,      1)
FLD_RAW_RW_DEF(         module_absence_e_proc_reg,  p33_mod_abs_proc,           0,      1)
FLD_RAW_RW_DEF(         module_absence_f_proc_reg,  p48_mod_abs_proc,           7,      1)
FLD_RAW_RW_DEF(         module_absence_f_proc_reg,  p47_mod_abs_proc,           6,      1)
FLD_RAW_RW_DEF(         module_absence_f_proc_reg,  p46_mod_abs_proc,           5,      1)
FLD_RAW_RW_DEF(         module_absence_f_proc_reg,  p45_mod_abs_proc,           4,      1)
FLD_RAW_RW_DEF(         module_absence_f_proc_reg,  p44_mod_abs_proc,           3,      1)
FLD_RAW_RW_DEF(         module_absence_f_proc_reg,  p43_mod_abs_proc,           2,      1)
FLD_RAW_RW_DEF(         module_absence_f_proc_reg,  p42_mod_abs_proc,           1,      1)
FLD_RAW_RW_DEF(         module_absence_f_proc_reg,  p41_mod_abs_proc,           0,      1)
FLD_RAW_RO_DEF(         cpld_version_reg,           cpld2_rev_cap,              6,      2)
FLD_RAW_RO_DEF(         cpld_version_reg,           cpld2_rev_sub,              0,      6)

#endif /* __qsd61_aom_a_48_sfp_plus_cpld_reg_H__ */
