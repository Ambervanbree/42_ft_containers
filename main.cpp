# include <iostream>

struct node{
	int	n;
};

void	update_n(node &src, node &dest){
	if (src.n)
		dest = src;
}

int	main(void){
	struct node	*source = new node();
	struct node	*dest = new node();

	source->n = 5;

	std::cout << "dest before " << dest->n << std::endl;

	update_n(*source, *dest);

	std::cout << "dest after " << dest->n << std::endl;
}