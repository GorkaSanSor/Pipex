/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:42:05 by gsantill          #+#    #+#             */
/*   Updated: 2025/03/10 13:25:52 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Checks if a file has read, write, or execute permissions.
void ft_check_access(const char *pathname)
{
	if (access(pathname, R_OK) == 0)
		ft_printf("%s is readable\n", pathname);
	if (access(pathname, W_OK) == 0)
		ft_printf("%s is writeable\n", pathname);
	if (access(pathname, X_OK) == 0)
		ft_printf("%s is executable\n", pathname);
	if (access(pathname, R_OK|W_OK) == 0)
		ft_printf("%s is readable and writeable\n", pathname);
}

/*
PATH=/home/gsantill/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:
/sbin:/bin:/usr/games:/usr/local/games:/snap/bin

La función recorre las variables de entorno almacenadas en env.
Una vez encontrada la var. PATH, se salta los primeros 5 caracteres ("PATH=").
Devuelve un arreglo de cadenas (paths) que contiene todas las rutas separadas.
*/

// Retrieves the system's PATH environment variable and splits it into paths.
char    **ft_get_path(char **env)
{
	char **paths;
	
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			break;
		env++;
	}
	paths = ft_split((*env + 5), ':');
	return (paths);
}


