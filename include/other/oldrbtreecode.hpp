
			// void complex_delete(node_ptr current){
			// 	node_ptr	parent = current->_parent;
			// 	node_ptr	sister;
			// 	node_ptr	niece;
			// 	node_ptr	far_niece;

			// 	int dir = childDir(current);
			// 	parent->_child[dir] = NULL;
			// 	std::cout << "dir is " << dir << std::endl;
			// 	do{
			// 		sister 		= parent->_child[1 - dir];
			// 		niece 		= sister->_child[dir];
			// 		far_niece	= sister->_child[1 - dir];
					
			// 		// case 3: sister is RED, so her parent and her 2 children
			// 		// must be BLACK (or NULL). Rotate puts the parent between
			// 		// sister and current and they exchange colors. Tree is still
			// 		// inbalanced, so we don't return.
			// 		if (sister->_color == RED){
			// 			rotate_dir(parent, dir);
			// 			parent->_color = RED;
			// 			sister->_color = BLACK;
			// 			sister = niece;
			// 			far_niece = sister->_child[1 - dir];
			// 			if (far_niece != NULL && far_niece->_color == RED){
			// 				rotate_dir(parent, dir);
			// 				sister->_color = parent->_color;
			// 				parent->_color = BLACK;
			// 				far_niece->_color = BLACK;
			// 				return ;
			// 			}
			// 			niece = sister->_child[dir];
			// 			if (niece != NULL && niece->_color == RED){
			// 				rotate_dir(sister, 1 - dir);
			// 				sister->_color = RED;
			// 				niece->_color = BLACK;
			// 				far_niece = sister;
			// 				sister = niece;
			// 			}
			// 		}
			// 		// case 6: sister is BLACK
			// 		if (far_niece != NULL && far_niece->_color == RED){
			// 			visualise();
			// 		std::cout << "yes here " << std::endl;
			// 			rotate_dir(parent, dir);
			// 			visualise();
			// 			sister->_color = parent->_color;
			// 			parent->_color = BLACK;
			// 			far_niece->_color = BLACK;
			// 			return ;						
			// 		}
			// 		// case 5: 
			// 		if (niece != NULL && niece->_color == RED){
			// 			rotate_dir(sister, 1 - dir);
			// 			sister->_color = RED;
			// 			niece->_color = BLACK;
			// 			far_niece = sister;
			// 			sister = niece;						
			// 		}
			// 		// case 4: both nephews are NULL (1st it) or BLACK (higher it)
			// 		if (parent->_color == RED){
			// 			sister->_color = RED;
			// 			parent->_color = BLACK;
			// 			return ;
			// 		}
			// 		// case 1: parent, niece, far niece en sister are black
			// 		sister->_color = RED;
			// 		current = parent;
			// 		dir = childDir(current);	
			// 	} while ((parent = current->_parent)!= NULL);
			// }
				



			bool simple_delete(node_ptr current){				
				if (current == _root){
					if (!current->_left && !current->_right) {_root = NULL; }
					else if (current->_left && current->_right) {
						std::cout << "find predecessor or successor" << std::endl; return true; 
						// hiervoor is iterator nodig 
						}
					else{
						if (current->_left) {_root = current->_left; }
						else {_root = current->_right; }
					}
					return true;
				}
				int dir = childDir(current);
				if (current->_color == RED && !current->_left && !current->_right){
					current->_parent->_child[dir] = NULL;
				}
				else if (current->_color == RED && (current->_left || current->_right)){
					if (current->_right){
						current->_right->_color = BLACK;
						current->_parent->_child[dir] = current->_right;
					}
					else {
						current->_left->_color = BLACK; 
						current->_parent->_child[dir] = current->_left;
					}
				}
				else
					return false;
				// delete node for real
				return true;
			}

			void delete_node(node_ptr current){
				// case 0: simple delete handles all cases where the current node
				// is RED and/or the root of the tree.
				if (simple_delete(current)) {return; }
				if (current->_color == BLACK && !current->_left && !current->_right){
					complex_delete(current);
					return ;
				}
				std::cout << "nog niet" << std::endl;
			}



/// NOT BAD

			bool root_simple_delete(node_ptr current){
				if (current == _root){
					if (!current->_left && !current->_right) {_root = NULL; }
					else if (current->_left && current->_right) {
						std::cout << "find predecessor or successor" << std::endl; return true; 
						// hiervoor is iterator nodig 
						}
					else if (current->_left) {_root = current->_left; }
					else if (current->_right) {_root = current->_right; }
					else {return false; }
				}
				else {return false; }
				// delete node for real
				return true;
			}
				
			bool simple_delete(node_ptr current){
				if (current->_color == RED){
					int dir = childDir(current);
					if (!current->_left && !current->_right){
						current->_parent->_child[dir] = NULL;
					}
					else if (current->_left && !current->_right){
						current->_left->_color = BLACK; 
						current->_parent->_child[dir] = current->_left;
					}
					else if (current->_right && !current->_left){
						current->_right->_color = BLACK;
						current->_parent->_child[dir] = current->_right;
					}
					else {return false; }
				}
				if (current->_color == BLACK){
					if (current->_left && !current->_right){
						if (current->_left->_color == RED){
							current->_left->_color = BLACK;
							current->_parent->_left = current->_left;
						}
					}
					else if (current->_right && !current->_left){
						if (current->_right->_color == RED){
							current->_right->_color = BLACK;
							current->_parent->_right = current->_right;
						}
					}
					else {return false; }
				}
				// delete node for real
				return true;
			}

			void delete_node(node_ptr current){
				if (simple_delete(current) || root_simple_delete(current)) {
					std::cout << "simple triggered" << std::endl; return ;}
				
				int 		dir 		= childDir(current);
				node_ptr 	parent 		= current->_parent;
				node_ptr	sister 		= parent->_child[1 - dir];
				std::cout << "sister is " << sister->_content << " (" << sister->_color << ")" << std::endl;
				node_ptr	niece 		= sister->_child[dir];
				node_ptr	far_niece	= sister->_child[1 - dir];

				if (sister->_color == BLACK){
					
					if (!far_niece && niece->_color == RED){
						rotate_dir(sister, 1 - dir);
						//color flip the two or lip completely
					}
				}
				else{
					std::cout << "nothin happened" << std::endl;
				}
			}




// BST code:

void delete (node_ptr root, int data)