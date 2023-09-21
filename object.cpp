/*
 * Description: implementation of object.hpp
 * Author: HBF
 * Version: 2021-08-24
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "object.hpp"
#include "menu.hpp"

extern int option;
void insert(LIST *list, SHAPE *object) {
// ...
	NODE* new_node = new NODE();
	new_node->object = object;
	new_node->next = list->start;
	new_node->prev = NULL;
	if (list->start != NULL) {
		list->start->prev = new_node;
	}
	list->start = new_node;
}

void deleteNode(LIST *list, NODE **selectp) {
// ...
	if (list->start == NULL || selectp == NULL) {
		return;
	}
	if (list->start->object == (*selectp)->object) {
		list->start = (*selectp)->next;
	}
	if ((*selectp)->next != NULL) {
		(*selectp)->next->prev = (*selectp)->prev;
	}
	if ((*selectp)->prev != NULL) {
		(*selectp)->prev->next = (*selectp)->next;
	}
	free(selectp);
}

void clearList(LIST *list) {
// ...
	/*NODE** head = list->start;
	while ((*head)->next != NULL) {
		head = list->start;
		list->start = list->start->next;
		deleteNode(list,head);
	}
	*/
}

void drawShape(SHAPE *object) {
	if (object->type == RECTANGLE) {  // rectangle
		// draw filled rectangle
		glBegin(GL_POLYGON);
		glVertex2i(object->x1,object->y1);
		glVertex2i(object->x2,object->y1);
		glVertex2i(object->x2,object->y2);
		glVertex2i(object->x1,object->y2);
		glEnd();
		// draw outline
		if (option == 1) {
		glBegin(GL_LINE_LOOP);
		glVertex2i(object->x1,object->y1);
		glVertex2i(object->x2,object->y1);
		glVertex2i(object->x2,object->y2);
		glVertex2i(object->x1,object->y2);
		glEnd();
		}

	} else if (object->type == CIRCLE) {  // circle
		// draw filled circle
		if (option == 0) {
		circleMidpointFill(object->x1,object->y1,object->x2,object->y2);
		}
		// draw outline
		if (option == 1) {
		circleMidpoint(object->x1,object->y1,object->x2,object->y2);
		}
	}
}

void drawShapeHighLight(SHAPE *object) {
	// draw outline with high light color
}

void drawList(LIST *list) {
	NODE *p = list->start;
	while (p) {
		drawShape(p->object);
		p = p->next;
	}
}

void setPixel(GLint x, GLint y) {
	glPointSize(2.0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

// draw points on line of circle
void circlePlotPoints(const GLint& xc, const GLint& yc, const GLint& x,
		const GLint& y) {
// ...
	setPixel(xc + x, yc + y);
	setPixel(xc + x, yc - y);
	setPixel(xc + y, yc + x);
	setPixel(xc + y, yc - x);
	setPixel(xc - x, yc + y);
	setPixel(xc - x, yc - y);
	setPixel(xc - y, yc + x);
	setPixel(xc - y, yc - x);
}

// draw circle main function
void circleMidpoint(GLint x1, GLint y1, GLint x2, GLint y2) {
	// r^2 = x^2 + y^2
	int r = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	int p = 1 - r;
	int x = 0;
	int y = r;
	//plot initial points in each circle quadrant
	circlePlotPoints(x1,y1,x,y);
	while (x<y) {
		x++;
		if (p < 0) {
			p += 2*x + 1;
		}
		else {
			y--;
			p += 2 * (x-y) + 1;
		}
		circlePlotPoints(x1,y1,x,y);
	}
}

void circlePlotPointsFill(GLint x1, GLint y1, GLint x, GLint y) {
	// ...
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(x1-x,y1+y);
	glVertex2i(x1-x,y1-y);
	glVertex2i(x1-y,y1+x);
	glVertex2i(x1-y,y1-x);
	glVertex2i(x1+x,y1+y);
	glVertex2i(x1+x,y1-y);
	glVertex2i(x1+y,y1+x);
	glVertex2i(x1+y,y1-x);
	glEnd();
}

void circleMidpointFill(GLint x1, GLint y1, GLint x2, GLint y2) {
	// ...
	int r = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		int p = 1 - r;
		int x = 0;
		int y = r;
		//middle
		circlePlotPointsFill(x1,y1,x2,y2);
		while (x<y) {
			x++;
			if (p < 0) {
				p += 2*x + 1;
			}
			else {
				y--;
				p += 2*(x-y) + 1;
			}
			circlePlotPointsFill(x1,y1,x2,y2);
		}
}
