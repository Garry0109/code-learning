# =================================================================
# 起始位置（Start）: 82
# 间隔步长（Stride）: 2
# 嵌入位数（Bit Depth）: 1
# =================================================================
STRIDE=2
def modify(value,pix,start,size):
    for i in range(size):
        one_bit=0x01&value
        pix[start+STRIDE*i]=pix[start+STRIDE*i]&0xFE|one_bit
        value>>=1

def hidden_logic(img_data, info_text):
    """
    将 info_text 隐藏到 img_data 的像素数据中。

    参数:
        img_data (bytearray): 图片原始二进制数据
        info_text (str):      待隐藏的字符串
    返回:
        bytearray: 嵌入信息后的图片数据
    """
    
	# 将待隐藏的字符串转换为若干个 8 位二进制数
    info_bytes = info_text.encode('utf-8')
    modify(len(info_bytes),img_data,82,64)
    for i in range(len(info_bytes)):
        offset=82+64*STRIDE+i*STRIDE*8
        modify(info_bytes[i],img_data,offset,8)


    

    # TODO: 根据给出的参数值，实现信息隐藏逻辑
	


    return img_data

# ==================== 以下代码请勿修改 ====================
if __name__ == "__main__":
    try:
        with open('picture.bmp', 'rb') as f:
            img_in = bytearray(f.read())
        with open('info.txt', 'r', encoding='utf-8') as f:
            txt_in = f.read()

        img_out = hidden_logic(img_in, txt_in)

        with open('output.bmp', 'wb') as f:
            f.write(img_out)
    except Exception as e:
        print(f"Error: {e}")
