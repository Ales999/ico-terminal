#pragma once
#include "TradePrice.h"

#include <QObject>
#include <QtCharts/QChartGlobal>

#include <vector>
#include <QColor>

QT_CHARTS_BEGIN_NAMESPACE
class QAbstractSeries;
class QLineSeries;
class QCandlestickSeries;
QT_CHARTS_END_NAMESPACE

using namespace QtCharts;
using namespace Entity;

namespace ChartCore
{
	enum ChartSeriesType : uint8_t
	{
		Line,
		Candlestick
	};

	class Series : public QObject
	{
		Q_OBJECT

	public:
		Series(QObject *parent = nullptr);

		// ������������� 
		void init(ChartSeriesType);
		// ����� ���� �����
		void change(ChartSeriesType);
		// ���������� ������ � �����
		void append(const TradePrice&);
		// �������
		void clear();

		// �������� ������� ��������
		void removeFirst();
		// �������� ���������� ��������
		void removeLast();
		// ��������� ������� �������� ������ �� ���������� TradePrice
		void removeTo(const TradePrice&);

		// ���������� ���������� �������� � �����
		void updateLastTrade(const TradePrice& trade);

		// ��������� �����
		QAbstractSeries* getSeries() const;
		QAbstractSeries* getAmount() const;

		// ������ �������/������ ������� ����
		void processRange(time_t start, time_t end);

		// ������� ������� ����
		double getMax() const;
		// ������ ������� ����
		double getMin() const;

		double getMaxAmount() const;

		TradePrice getLastTrade() const;

		size_t size() const;

	private:
		ChartSeriesType type = ChartSeriesType::Line;

		// data
		std::vector<TradePrice> data;

		QAbstractSeries* main = nullptr;

		QLineSeries*        line        = nullptr;
		QCandlestickSeries* candlestick = nullptr;

		double max = DBL_MIN;
		double min = DBL_MAX;

		double maxAmount = 0;

		TradePrice lastTradePrice;

		// amount 

		QLineSeries *amount = nullptr;

		std::vector<QAbstractSeries *> seriesVector;
	};
}