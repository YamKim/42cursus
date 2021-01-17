#include "./incs/libasm.h"
#include <stdio.h>

void printf_list(t_list *list) {
	while (list) {
		printf("addr: %p\n", list);
		printf("next: %p\n", list->next);
		printf("data: %d\n", *(int *)(list->data));
		list = list->next;
	}
}

int compare(void *a, void *b) {
	return (*(int *)a - *(int *)b);
}

int compare_greater(void *a, void *b) {
	return (*((int *)a) - *((int *)b));
}

void ft_lstclear(t_list **list) {
	t_list	*tmp;

	while (*list) {
		tmp = (*list)->next;

		printf("free addr: %p\n", *list);
		printf("free data: %d\n", *(int *)((*list)->data));
#if 0
		if ((*list)->data)
			free((*list)->data);
#endif
		free(*list);
		*list = tmp;
	}
}

#if 0
int		main(void) {
	t_list	*list = (t_list *)malloc(16);
	int i1 = 1, i2 = 2, i3 = 3, i4 = 4;
	(void)i1; (void)i2; (void)i3; (void)i4;

	list->data = &i1;
	list->next = NULL;
	ft_list_push_front(&list, &i3);
	ft_list_push_front(&list, &i2);
	ft_list_push_front(&list, &i4);


	printf("before removing\n");
	printf("size: %d\n", ft_list_size(list));
	printf_list(list);

	printf("after sort\n");
	list = ft_list_sort(list, compare_greater);
	printf_list(list);


#if 0
	printf("after removing\n");
	//ft_list_remove_if(&list, &i2, compare);
	printf("size: %d\n", ft_list_size(list));
	printf_list(list);
#endif
	ft_lstclear(&list);
	while(1);

	return (0);
}
#endif

int main(void) {
	printf("result: %d\n", ft_atoi_base("123", "1"));
	printf("result: %d\n", ft_atoi_base("123", ""));
	printf("result: %d\n", ft_atoi_base("123", "10+02"));
	printf("result: %d\n", ft_atoi_base("123", "1 02"));
	printf("result: %d\n", ft_atoi_base("123", "1-02"));
	printf("result: %d\n", ft_atoi_base("123", "122"));
	printf("result: %d\n", ft_atoi_base("123", "0123456789"));
	printf("result: %d\n", ft_atoi_base("-+0123", "0123456789abcdef"));

	return (0);
}
