#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#define INIT_SIZE 1
#define INCREMENT_SIZE 5
typedef struct {
    int id; //ѧ��
    int age; //����
    char name[10]; //����
} Student;

typedef Student ElemType;

typedef struct {
    ElemType *base;
    int size; /* ˳����������� */
    int length; /* ��¼˳����Ԫ�ظ��� */
} SqList;

/**
 * ��ʼ��˳���
 * @param p ָ��˳����ָ��
 * @return �����ʼ���ɹ�����true���򷵻�false
 */
bool init(SqList *p) {
    p->base = malloc(sizeof(SqList) * INIT_SIZE);
    if (p->base == NULL) {
        return false;
    }
    p->size = INIT_SIZE;
    p->length = 0;
    return true;
}

/**
 * ָ��λ�ò�������Ԫ��
 * @param p ָ��˳����ָ��
 * @param index ������±�
 * @param elem �����Ԫ��ֵ
 * @return �������ɹ�����true�����򷵻�false
 */
bool insert(SqList *p, int index, ElemType elem) {
    if (index < 0 || index > p->length) {
        perror("�����±겻�Ϸ�");
        return false;

    }

    //���˳������ˣ������·�����������
    if (p->length == p->size) {
        int newSize = p->size + INCREMENT_SIZE;
        ElemType *newBase = realloc(p->base, newSize);
        if (newBase == NULL) {
            perror("˳������������·����ڴ�ʧ��");
            return false;
        }
        p->base = newBase;
        p->size = newSize;
    }

    //�����һ��Ԫ�ؿ�ʼ���ΰ�Ԫ�ظ��Ƶ������λ��
    for (int i = p->length - 1; i >= index; --i) {
        p->base[i + 1] = p->base[i];
    }
    p->base[index] = elem;
    p->length++;
    return true;
}

/**
 * ɾ��ָ���±������Ԫ��
 * @param p ָ��˳����ָ��
 * @param index ɾ����Ԫ�ص��±�
 * @param elem ����ɾ����Ԫ��
 * @return ���ɾ���ɹ�����true���򷵻�false
 */
bool del(SqList *p, int index, ElemType *elem) {
    if (p->length == 0) {
        perror("˳���ǿյģ��޷�ִ��ɾ������");
        return false;
    }
    if (index < 0 || index > p->length - 1) {
        perror("ɾ��λ�ò��Ϸ�");
        return false;
    }

    //��ɾ����Ԫ�ر�������
    *elem = p->base[index];
    //��ɾ��λ�ÿ�ʼ���ΰѺ����Ԫ�ظ�ֵ��ǰ��
    for (int i = index; i < p->length - 1; ++i) {
        p->base[i] = p->base[i + 1];
    }
    p->length--;
    return true;
}

/**
 * ����˳������ض���Ԫ��ֵ
 * @param p ָ��˳����ָ��
 * @param index �����±�
 * @param elem ���ĺ����Ԫ��ֵ
 * @return ������ĳɹ��򷵻�true�����򷵻�false
 */
bool update(SqList *p, int index, ElemType elem) {
    if (p->length == 0) {
        perror("˳����ǿյģ��޷�ָ�����");
        return false;
    }

    if (index < 0 || index > p->length - 1) {
        perror("�����±겻�Ϸ�");
        return false;
    }

    p->base[index] = elem;
    return true;
}

/**
 * ����˳������ض��±��Ԫ��
 * @param list ָ����˳���
 * @param index �������±�
 * @param elem ������������Ԫ��
 * @return ��������ɹ��򷵻�true�����򷵻�false
 */
bool search(SqList list, int index, ElemType *elem) {
    if (list.length == 0) {
        perror("˳���û���κ�Ԫ�أ��޷�����");
        return 0;
    }

    if (index < 0 || index > list.length - 1) {
        perror("�����±겻�Ϸ�");
        return false;
    }

    *elem = list.base[index - 1];
    return true;
}

/**
 * ��ӡ˳���
 * @param list ָ��˳���
 */
void output(SqList list) {
    printf("ѧ��\t����\t����\n");
    for (int i = 0; i < list.length; ++i) {
        printf("%d\t%d\t%s\n", list.base[i].id, list.base[i].age, list.base[i].name);
    }
    printf("\n");
}

int main() {
    SqList list;
    while (1) {
        printf("\t\t˳���Ļ�������\n");
        printf("\t\t1.��ʼ��˳���\n");
        printf("\t\t2.˳���Ĳ���\n");
        printf("\t\t3.˳����ɾ��\n");
        printf("\t\t4.˳���Ĳ���(�±�)\n");
        printf("\t\t5.˳�����޸�\n");
        printf("\t\t6.��ӡ\n");
        printf("\t\t0.�˳�\n");

        int choice;
        printf("�����빦�ܱ��:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (init(&list)) {
                    printf("��ʼ���ɹ�\n");
                }
                assert(list.length == 0);
                break;
            case 2:;
                ElemType elem;
                printf("����������ѧ��ѧ��:");
                scanf("%d", &elem.id);
                printf("����������ѧ������:");
                scanf("%d", &elem.age);
                printf("����������ѧ������:");
                scanf("%s", elem.name);

                printf("���������λ��:");
                int index;
                scanf("%d", &index);

                if (insert(&list, index, elem)) {
                    printf("����ɹ�\n");
                }
                break;
            case 3:
                printf("������ɾ��λ��:");
                scanf("%d", &index);
                if (del(&list, index, &elem)) {
                    printf("ɾ����ѧ�� ѧ��:%d\t����:%d\t����:%s\n", elem.id, elem.age, elem.name);
                }
                break;
            case 4:
                printf("������Ҫ���ҵ�λ��:");
                scanf("%d", &index);
                if (search(list, index, &elem)) {
                    printf("���ҵ�ѧ�� ѧ��:%d\t����:%d\t����:%s\n", elem.id, elem.age, elem.name);
                }
                break;
            case 5:
                printf("���������λ��:");
                scanf("%d", &index);

                printf("��������º��ѧ��ѧ��:");
                scanf("%d", &elem.id);
                printf("��������º��ѧ������:");
                scanf("%d", &elem.age);
                printf("��������º��ѧ������:");
                scanf("%s", elem.name);
                if (update(&list, index, elem)) {
                    printf("���³ɹ�\n");
                }
                break;
            case 6:
                output(list);
                break;
            case 0:
                exit(0);
            default:
                printf("��������������������\n");
                break;
        }
    }
    return 0;
}

