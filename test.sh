# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/28 22:21:33 by sdummett          #+#    #+#              #
#    Updated: 2021/08/28 22:25:41 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# This test will only do the range 1 - 10
ARG=$(ruby -e "puts (1..10).to_a.shuffle.join(' ')"); ./push_swap $ARG; echo $ARG
