/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:19:51 by joivanau          #+#    #+#             */
/*   Updated: 2022/09/20 00:12:43 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_LINE		"ERROR: Line doesn't get initialized"
# define READ_ERROR		"ERROR: Line doesn't get read"

# define ERR_LEM		"ERROR: Lem struct doesn't get initilized"
# define ENOUGH_ANTS	"ERROR: Not enough ants"
# define ANT_NOT_NUM	"ERROR: Ant line is not numeric"

# define ERR_SPLIT		"ERROR: Error at reading room"

# define ERR_ROOM_CR	"ERROR: Room doesn't get initialized"
# define ROOM_NAME_DUP	"ERROR: Room name duplicates"
# define ROOM_CORD_DUP	"ERROR: Room coordinates duplicates"
# define ERR_ROOM		"ERROR: Room doesn't get created"
#endif