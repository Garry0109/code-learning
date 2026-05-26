# =================================================================
# 起始位置（Start）: 82
# 间隔步长（Stride）: 2
# 嵌入位数（Bit Depth）: 1
# =================================================================
STRIDE=2

def modify(pix,start,size):
    value=0
    for i in range(size):
        bit=pix[start+i*STRIDE]&0x01
        value|=(bit<<i)
    return value

def extract_logic(img_data):
    """
    从 img_data 的像素数据中提取隐藏的字符串。

    参数:
        img_data (bytearray): 包含隐写信息的图片二进制数据
    返回:
        str: 提取出的字符串
    """
    text_len=modify(img_data,82,64)
    

	# 将提取出的二进制数据存储在 extracted_bytes 中
    extracted_bytes = bytearray()
    for i in range(text_len):
        offset=82+64*STRIDE+i*8*STRIDE
        extracted_bytes.append(modify(img_data,offset,8))



    # TODO: 根据给出的参数值，实现信息提取逻辑
	

    try:
        return extracted_bytes.decode('utf-8')
    except UnicodeDecodeError:
        return "解码失败：提取出的二进制数据无法转换为有效的 UTF-8 字符串，请检查提取逻辑。"

# ==================== 以下代码请勿修改 ====================
if __name__ == "__main__":
    try:
        with open('picture.bmp', 'rb') as f:
            img_in = bytearray(f.read())
        result_text = extract_logic(img_in)
        print(result_text)
    except FileNotFoundError:
        print("Error: file picture.bmp not found.")
    except Exception as e:
        print(f"Error: {e}")
