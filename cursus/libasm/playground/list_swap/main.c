#include <stdio.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

#if 0
void swap_list(t_list *lst1, t_list *lst2) {
	void *tmp = lst1->data;
	lst1->data = lst2->data;
	lst2->data = tmp;
}
#endif
extern void swap_list(t_list *lst1, t_list *lst2);

int main(void) {
	int i1 = 1;
	int i2 = 2;
	int i3 = 3;

	t_list list3 = {&i3, NULL};
	t_list list2 = {&i2, &list3};
	t_list list1 = {&i1, &list2};

	t_list *pos = &list1;
	while (pos) {
		printf("addr: %p\n", &(pos + 1));
		printf("data addr: %p\n", &(pos->next));
		printf("data: %d\n", *(int *)(pos->data));
		pos = pos->next;
	}

	swap_list(&list1, &list3);

	printf("AFTER SWAPPING!\n");
	pos = &list1;
	while (pos) {
		printf("addr: %p\n", &(pos + 1));
		printf("data addr: %p\n", &(pos->next));
		printf("data: %d\n", *(int *)(pos->data));
		pos = pos->next;
	}


	return (0);
}
