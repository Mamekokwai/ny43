# MCU 已在 keyboard.json 中由 "processor" 定义，可删除
# 但保留频率与架构相关定义

# 芯片主频
F_CPU = 16000000
# USB 时钟
F_USB = $(F_CPU)

# 指定架构为 AVR8 位
ARCH = AVR8

# LUFA 中断驱动端点
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT

# Bootloader 大小（字节）,不被覆盖
OPT_DEFS += -DBOOTLOADER_SIZE=4096

# 启用 LTO,减小固件大小
LTO_ENABLE = yes

# 启用 NKRO,支持多键同时按下
NKRO_ENABLE = yes

# 启用共享端点,支持多键同时按下
KEYBOARD_SHARED_EP = yes

# 启用鼠标键,支持鼠标移动
#MOUSEKEY_ENABLE = yes

# 启用鼠标共享端点,支持鼠标移动
#MOUSE_SHARED_EP = yes


# 其余功能均已迁移至 keyboard.json，请勿在此重复定义