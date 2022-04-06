#pragma once

#include <stdlib.h>

// DynamicArray�� ����� �迭 ����� �ڷ���
typedef int Element;

typedef struct {
    Element* arr; //4바이트 짜리 배열 하나가 생성됨.
    int count; // ���� �ε��� ��ȣ ����
    int size;  // �迭�� ũ�� ����
} DynamicArray;

// Element�� �ش�Ǵ� �ڷḦ ȭ�鿡 ����ϴ� �Լ����� ��ǥ�ϴ� �ڷ���
typedef void(*PrintFunc)(Element e);

// DynamicArray�� ����
DynamicArray* DACreate();
// DynamicArray�� �� �ڸ��� value�� �߰�
int DAAdd(DynamicArray* resizableArray, Element value);
// DynamicArray�� idx �ε��� ��ġ�� value ���� ����
int DAPut(DynamicArray* resizableArray, int idx, Element value);
// DynamicArray���� idx �ε����� �ش�Ǵ� ��� ���� value ������ ���ؼ� ��ȯ
int DAGet(const DynamicArray* resizableArray, int idx, Element* value);
// DynamicArray�� �ִ� ������ ���� ��ȯ
// ������ ������ -1 ��ȯ
int DAGetCount(const DynamicArray* resizableArray);
// DynamicArray���� �Ҵ�� ��ü �迭�� ũ�� ��ȯ
// ������ ������ -1 ��ȯ
int DAGetSize(const DynamicArray* resizableArray);
// DynamicArray�� �Ҵ�� �迭 �� DynamicArray ����ü ����
int DADestroy(DynamicArray* resizableArray);
// DynamicArray�� �ִ� ��ҵ��� printFunc�� �̿��ؼ� ȭ�鿡 ���
int DAPrint(const DynamicArray* resizableArray, PrintFunc printFunc);