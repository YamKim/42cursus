#include "./incs/libasm_bonus.h"

#define DEBUG_FT_ATOI_BASE 0
#define DEBUG_FT_LIST 1

void printf_list(t_list *list);
void ft_list_clear(t_list **list);
int compare_greater(void *a, void *b);
int compare(void *a, void *b);
void free_fct(void *data);

#if DEBUG_FT_ATOI_BASE
#define FT_ATOI_BASE(str, base)\
		printf("base: [%ld], result:[%d]\n",\
		ft_strlen(base), ft_atoi_base(str, base));

int main(void) {
	FT_ATOI_BASE("42", "");
	FT_ATOI_BASE("42", "1");
	FT_ATOI_BASE("42", "10+2");
	FT_ATOI_BASE("42", "10 2");
	FT_ATOI_BASE("42", "10-2");
	FT_ATOI_BASE("42", "4242");

	FT_ATOI_BASE("-+-42", "0123456789");

	FT_ATOI_BASE("101010", "01");
	FT_ATOI_BASE("111", "314");
	FT_ATOI_BASE("42", "0123456789");
	FT_ATOI_BASE("42", "0123456789abcdef");

	return (0);
}
#endif

#if DEBUG_FT_LIST
int	main(void) {
	t_list	*list = (t_list *)malloc(16);
	int *i1 = (int *)malloc(sizeof(int));
	int *i2 = (int *)malloc(sizeof(int));
	int *i3 = (int *)malloc(sizeof(int));
	int *i4 = (int *)malloc(sizeof(int));
	int *i5 = (int *)malloc(sizeof(int));
	*i1 = 1; *i2 = 2; *i3 = 3; *i4 = 4; *i5 = 5;

	list->data = i1;
	list->next = NULL;
	ft_list_push_front(&list, i3);
	ft_list_push_front(&list, i2);
	ft_list_push_front(&list, i4);
	ft_list_push_front(&list, i5);

	printf("After pushing data===================\n");
	printf_list(list);
	printf("========= size of list: [%d] =========\n\n", ft_list_size(list));

	printf("After sorting list===================\n");
	ft_list_sort(&list, compare_greater);
	printf_list(list);
	printf("========= size of list: [%d] =========\n\n", ft_list_size(list));

	printf("After removing list==================\n");
	ft_list_remove_if(&list, i2, compare, free_fct);
	//ft_list_remove_if(&list, "", compare, free_fct);
	printf_list(list);
	printf("========= size of list: [%d] =========\n\n", ft_list_size(list));

	ft_list_clear(&list);

	return (0);
}
#endif

void printf_list(t_list *list) {
	while (list) {
		printf("addr: %p\n", list);
		printf("next: %p\n", list->next);
		printf("data: %d\n", *(int *)(list->data));
		list = list->next;
	}
}

void ft_list_clear(t_list **list) {
	t_list	*tmp;

	while (*list) {
		tmp = (*list)->next;

		printf("free addr: %p\n", *list);
		printf("free data: %d\n", *(int *)((*list)->data));
		free(*list);
		*list = tmp;
	}
}

int compare(void *a, void *b) {
	return (*(int *)a - *(int *)b);
}

int compare_greater(void *a, void *b) {
	return (*((int *)a) - *((int *)b));
}

void free_fct(void *data) {
	free(data);
}
