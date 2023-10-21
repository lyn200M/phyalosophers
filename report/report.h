/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnyamets <lnyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:08:21 by lnyamets          #+#    #+#             */
/*   Updated: 2023/10/21 17:53:27 by lnyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPORT_H
# define REPORT_H
# include <stdio.h>
# define NUMBER_ARGUMENTS_ERROR "Numbers Arguments is wrong. Need min 4 max 5"
# define ARGUMENTS_NOT_NUMBER_ERROR "Good Args Nbrs but just numbers accept"
# define CHECK_ARGS_OK_LOG "Numbers of Args is OK and is all numbers"

void	report_log_error(char  *error_msg);
void	report_log_info(char  *info_msg);
#endif
