/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@42kocaeli.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:30:08 by faozturk          #+#    #+#             */
/*   Updated: 2022/04/26 14:33:06 by faozturk         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_events(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		game->y_player -= 1; // w yukarı tuşu yani y değerini bir birim azalması demek. yukarı doğru y azalır
		player_w(game);
	}
	else if (keycode == KEY_S)
	{
		game->y_player += 1; // s basılması y konumunun bir artması demek çünkü y aşağı gittikçe artar
		player_s(game);
	}
	else if (keycode == KEY_D)
	{
		game->x_player += 1; // d tuşuna basılınca sağa doğru harekette x bir birim artar.
		player_d(game);
	}
	else if (keycode == KEY_A)
	{
		game->x_player -= 1; // a tuşuna basılınca sola doğru harektte x bir birim azalır.
		player_a(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)  // esc ve q ya basınca ekranı kapatır ve oyundan çıkar
		exit_game(game);
	else if (!game->endgame) // oyun sonlanmadıysa !0 = 1 içeri girer.
	{
		game_events(keycode, game);
		printf("Moves: %d\n", game->moves);
	}
	return (0);
}

void	gameplay(t_game *game) //mlx_hook eventları yakalar. Event geldiğinde onu ilgili fonksiyona yönlendirir.
{
	mlx_hook(game->win, 2, 0, keypress, game);  // eventları yakalamaya yarayan fonksiyon ON_KEYDOWN = 2 tuşa basıldığını gösterir. tuşu aşağı ittiğimiz için.
	mlx_hook(game->win, 17, 0, exit_game, game); // 0 maskeleme için ama bizim kütüphanede bu kısım desteklenmiyor o yüzden kullanmayıp 0 veriyoruz. ON_DESTROY = 17 pencerenin sol üst kçşesindeki x ya basıldığında iletilir.  
	mlx_hook(game->win, 12, 0, map_draw, game); // ON_EXPOSE = 12 (açığa çıkarmak). Oyunu yeniden çizmek için gerekli event.
}
