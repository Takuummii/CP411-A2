/*
 * Description: implementation of edit.hpp
 * Author: HBF
 * Version: 2021-08-24
 */

#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include "object.hpp"

extern LIST objlist;

GLint min(GLint x, GLint y) {
	return x < y ? x : y;
}

GLint max(GLint x, GLint y) {
	if (x < y)
		return y;
	else
		return x;
}

NODE *select(GLint x, GLint y) {
	// your implementation
    // search the object that cover the clicking point staring
	int selected = -1;
	int counter = 0;
	NODE *ptr = objlist.start;
	while (ptr->next != NULL) {
		if (ptr->object->x1 > ptr->object->x2) {
			int temp = ptr->object->x2;
			ptr->object->x2 = ptr->object->x1;
			ptr->object->x1 = temp;
		}
		if (ptr->object->y1 > ptr->object->y2) {
			int temp = ptr->object->y2;
			ptr->object->y2 = ptr->object->y1;
			ptr->object->y1 = temp;
		}
		if (ptr->object->type == RECTANGLE && x <= ptr->object->x2 && x >= ptr->object->x1 && y <= ptr->object->y2 && y >= ptr->object->y1) {
			selected = counter;
		}
		else if () {

		}
		counter++;
		ptr = ptr->next;
	}
	return NULL;
}

void Delete(NODE **pp) {
	// your implementation

}

void moveFront(NODE *p) {
	// your implementation
}

void moveBack(NODE *p) {
	// your implementation
}

