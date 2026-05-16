/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:05:28 by lupin             #+#    #+#             */
/*   Updated: 2026/05/16 21:18:26 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

/**
 * @struct s_stack
 * @brief Structure used to store stack elements.
 * @var s_stack::value Value stored in the stack element.
 * @var s_stack::next Pointer to the next element in the stack.
 * @var s_stack::prev Pointer to the previous element in the stack.
 */

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/**
 * @brief Creates a new stack node with the given content.
 * @param content Value to store in the new node.
 * @return Pointer to the newly allocated node, or NULL on failure.
 */
t_stack	*new_node(long content);

/**
 * @brief Adds the node `new` at the beginning of the list represented by `lst`.
 * @param lst Address of the pointer to the list head (may be updated).
 * @param new Node to insert at the front.
 */
void	add_node_front(t_stack **lst, t_stack *new);

/**
 * @brief Adds the node `new` at the end of the list represented by `lst`.
 * @param lst Address of the pointer to the list head (may be updated).
 * @param new Node to insert at the back.
 */
void	add_node_back(t_stack **lst, t_stack *new);

/**
 * @brief Returns the number of elements in the list.
 * @param lst Pointer to any node of the list (function walks the list).
 * @return Number of elements in the list.
 */
int		lst_size(t_stack *lst);

/**
 * @brief Returns the last node in the list.
 * @param lst Pointer to any node of the list.
 * @return Pointer to the last node, or NULL if list is empty.
 */
t_stack	*last_node(t_stack *lst);

/**
 * @brief Returns the first node in the list.
 * @param lst Pointer to any node of the list.
 * @return Pointer to the first node, or NULL if list is empty.
 */
t_stack	*first_node(t_stack *lst);

#endif