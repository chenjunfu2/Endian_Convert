//tType目标类型 cpData数据 bDataIsBigEndian数据本身的顺序是否为大端字节序
template<typename T>
void ConvertEndianData2Type(T *tType, const char *cpData, bool bDataIsBigEndian)
{
	constexpr size_t szTypeByte = sizeof(*tType);
	*tType = 0;//置空

	if (bDataIsBigEndian)
	{
		for (int i = 0; i < szTypeByte; ++i)//正序遍历
		{
			(*tType) <<= 8;//移动一字节
			(*tType) |= cpData[i];//放在最低字节
		}
	}
	else
	{
		for (int i = szTypeByte - 1; i >= 0; --i)//倒序遍历
		{
			(*tType) <<= 8;//移动一字节
			(*tType) |= cpData[i];//放在最高字节
		}
	}
}

//cpData目标数据 tType类型 bDataIsBigEndian数据最终需要的顺序是否为大端字节序
template<typename T>
void ConvertEndianType2Data(char *cpData, const T *tType, bool bDataNeedBigEndian)
{
	constexpr size_t szTypeByte = sizeof(*tType);
	T tTypeTemp = *tType;

	if (bDataNeedBigEndian)
	{
		for (int i = szTypeByte - 1; i >= 0; --i)//倒序遍历
		{
			cpData[i] = (char)tTypeTemp;//截断高字节
			tTypeTemp >>= 8;//右移一字节
		}
	}
	else
	{
		for (int i = 0; i < szTypeByte; ++i)//正序遍历
		{
			cpData[i] = (char)tTypeTemp;//截断高字节
			tTypeTemp >>= 8;//右移一字节
		}
	}
}