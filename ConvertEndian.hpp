//tTypeĿ������ cpData���� bDataIsBigEndian���ݱ����˳���Ƿ�Ϊ����ֽ���
template<typename T>
void ConvertEndianData2Type(T *tType, const char *cpData, bool bDataIsBigEndian)
{
	constexpr size_t szTypeByte = sizeof(*tType);
	*tType = 0;//�ÿ�

	if (bDataIsBigEndian)
	{
		for (int i = 0; i < szTypeByte; ++i)//�������
		{
			(*tType) <<= 8;//�ƶ�һ�ֽ�
			(*tType) |= cpData[i];//��������ֽ�
		}
	}
	else
	{
		for (int i = szTypeByte - 1; i >= 0; --i)//�������
		{
			(*tType) <<= 8;//�ƶ�һ�ֽ�
			(*tType) |= cpData[i];//��������ֽ�
		}
	}
}

//cpDataĿ������ tType���� bDataIsBigEndian����������Ҫ��˳���Ƿ�Ϊ����ֽ���
template<typename T>
void ConvertEndianType2Data(char *cpData, const T *tType, bool bDataNeedBigEndian)
{
	constexpr size_t szTypeByte = sizeof(*tType);
	T tTypeTemp = *tType;

	if (bDataNeedBigEndian)
	{
		for (int i = szTypeByte - 1; i >= 0; --i)//�������
		{
			cpData[i] = (char)tTypeTemp;//�ضϸ��ֽ�
			tTypeTemp >>= 8;//����һ�ֽ�
		}
	}
	else
	{
		for (int i = 0; i < szTypeByte; ++i)//�������
		{
			cpData[i] = (char)tTypeTemp;//�ضϸ��ֽ�
			tTypeTemp >>= 8;//����һ�ֽ�
		}
	}
}