/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:19:51 by joivanau          #+#    #+#             */
/*   Updated: 2022/10/09 19:43:37 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_LINE		"ERROR: Line doesn't get initialized"
# define READ_ERROR		"ERROR: Line doesn't get read"
# define ERR_START_END	"ERROR: Input doesn't have start or end room"

# define ERR_LEM		"ERROR: Lem struct doesn't get initilized"
# define ENOUGH_ANTS	"ERROR: Not enough ants"
# define ANT_NOT_NUM	"ERROR: Ant line is not numeric"

# define ERR_SPLIT		"ERROR: Error at reading room"

# define ERR_ROOM_CR	"ERROR: Room doesn't get initialized"
# define ROOM_NAME_DUP	"ERROR: Room name duplicates"
# define ROOM_CORD_DUP	"ERROR: Room coordinates duplicates"
# define ERR_ROOM		"ERROR: Room doesn't get created"

# define ERR_LINK		"ERROR: Link doesn't get created"
# define ERR_LINK_I		"ERROR: Link doesn't get initialized"
# define ERR_LINK_DUP	"ERROR: Link name duplicates"
# define ERR_NO_LINK	"ERROR: Zero links"

# define ERR_BFS_ALLOC	"ERROR: BFS couldn't allocate memory"
# define ERR_NEW_PATH	"ERROR: PATH couldn't allocate memory"
# define ERR_NEW_LOC	"ERROR: LOCATION couldn't allocate memory"
#endif