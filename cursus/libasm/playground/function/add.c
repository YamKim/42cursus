int is_positive(int nbr) {
	return (nbr >= 0);
}

int add(int nbr1, int nbr2) {
	int ret = -1;
	if (is_positive(nbr2))
		ret = nbr1 + nbr2;
	return (ret);
}
