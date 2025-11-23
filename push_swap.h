/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 23:05:32 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/23 13:55:43 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //malloc, free
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				value;
	int				position;
	int				f_idx;
	bool			above_median;
	bool			cheapest;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
}					t_node;

char	**ft_split(char const *s, char c);

#endif
