#include "TradeOrder.h"

void TradeOrder::buy(const double&)
{
	type = Long;
}

void TradeOrder::sell(const double&)
{
	type = Short;
}

void TradeOrder::close()
{
	//todo: � ����������� �� ���� ������� ��� ������
}
