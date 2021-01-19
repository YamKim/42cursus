void function2(void) {
	;
}

void function1(void) {
	function2();
}

int main(void) {
	function1();
	return (0);
}
