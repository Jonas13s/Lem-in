/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 23:16:40 by joivanau          #+#    #+#             */
/*   Updated: 2022/09/26 23:20:58 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include <errno.h>
# include "errors.h"
# include <stdio.h>

typedef enum
{
	START,
	MID,
	END
}	t_type;

typedef struct s_room
{
	char			*name;
	int				x;
	int				y;
	int				level;
	t_type			type;
	int				input;
	int				output;
	int				ant_number;
	struct s_room	*next;
}					t_room;

typedef struct s_queue
{
	t_room			*room;
	struct s_queue	*next;
}					t_queue;

typedef struct s_link
{
	t_room			*start;
	t_room			*end;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

typedef struct s_line
{
	char			*content;
	struct s_line	*next;
}					t_line;

typedef struct s_lemin
{
	int			start_ants;
	int			end_ants;
	int			ants;
	int			level;
	t_room		*rooms;
	t_room		*end;
	t_room		*start;
	t_link		*links;
}				t_lemin;

void	terminate(char	*str);

t_line	*read_line(t_line **lines);

void	get_ants(t_lemin *lem, t_line **cur, t_line **lines);
void	get_rooms(t_lemin *lem, t_line **cur, t_line **lines);
void	get_links(t_lemin *lem, t_line **cur, t_line **lines);
int		check_command(char *str);
int		check_comment(char *str);
int		check_room(char *str);
t_room	*find_room(t_lemin *lem, char *str);
void	bfs(t_lemin *lem);
void	bad_links(t_lemin *lem);
void	align_link(t_lemin *lem);
#endif