/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldumas- <fldumas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:53:34 by fldumas-          #+#    #+#             */
/*   Updated: 2025/12/11 19:06:30 by fldumas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

typedef struct  s_animation_stack
{
    struct animation_stack  *prev;
    struct animation_stack  *next;
}               t_animation_stack;

typedef struct s_object
{
    char    *animation;
    char    *sprite;
}               t_object;


#endif