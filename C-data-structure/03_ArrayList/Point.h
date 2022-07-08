#ifndef __POINT_H__
#define __POINT_H__

// Point ����ü ����
typedef struct _point {
	int xpos;
	int ypos;
} Point;

// xpos, ypos �� ����
void SetPointPos(Point* ppos, int xpos, int ypos);

// xpos, ypos ���� ���
void ShowPointPos(Point* ppos);

// �� Point ���� ��
int PointComp(Point* pos1, Point* pos2);

#endif