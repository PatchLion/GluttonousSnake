#ifndef GLUTTONOUSSNAKE_H
#define GLUTTONOUSSNAKE_H

#include <QtWidgets>
#include <QtGui>
#include <QtCore>

class CGluttonousSnake : public QWidget
{
	Q_OBJECT

public:
	enum Direction
	{
		Up        = -1,
		Down	= 1,
		Left      = -2,
		Right	= 2,
	};

public:
	CGluttonousSnake(QWidget *parent = 0);
	~CGluttonousSnake();

public:
	void reset(bool autoStart = true);

	void pause();
	void start();

protected:
	void paintEvent(QPaintEvent *event);
	void timerEvent(QTimerEvent *event);
	void keyPressEvent(QKeyEvent *event);

private:
	void onFailed();

	QList<QPoint>	m_snake;
	QList<QPoint> m_food;
	QList<QPoint> m_barrier;									//�ϰ�
	QList<QPoint> m_armourPiercingBullet;				//���׵�

	int						m_nArmourPiercingBullet;		//���׵�����(��ǽ)
	int						m_nTimerID;
	int						m_nCreateFoodTimerID;		//����ʳ���ʱ��
	int						m_nCreateBarrierTimerID;		//�����ϰ���ʱ��
	int						m_nCreateAPBTimerID;		//���ɴ��׵���ʱ��
	Direction				m_eCurrentDirection;		
	Direction				m_eNextDirection;
	int						m_nGridSize;

	bool					m_bIsPause;
};

#endif // GLUTTONOUSSNAKE_H
