/*
 * Copyright (c) 1980, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
#ifndef lint
__COPYRIGHT("@(#) Copyright (c) 1980, 1993\n\
	The Regents of the University of California.  All rights reserved.\n");
#endif /* not lint */

#ifndef lint
#if 0
static char sccsid[] = "@(#)expand.c	8.1 (Berkeley) 6/9/93";
#endif
__RCSID("$NetBSD: expand.c,v 1.6 1997/10/18 14:45:57 lukem Exp $");
#endif /* not lint */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

/*
 * expand - expand tabs to equivalent spaces
 */
int	nstops;
int	tabstops[100];

static	void	getstops __P((char *));
	int	main __P((int, char **));
static	void	usage __P((void));

int
main(argc, argv)
	int argc;
	char *argv[];
{
	int c, column;
	int n;

	/* handle obsolete syntax */
	while (argc > 1 && argv[1][0] && isdigit(argv[1][1])) {
		getstops(&argv[1][1]);
		argc--; argv++;
	}

	while ((c = getopt (argc, argv, "t:")) != -1) { // -1 はオプションが全て処理されたことを示す
		switch (c) {
		case 't':
			getstops(optarg);// optarg はオプションの引数
			// オプション引数からタブストップの値を決める
			break;
		case '?': // エラー戻り値
		default:
			usage();
			/* NOTREACHED */
		}
	}
	// optind は オプションではない引数の先頭i
	argc -= optind;
	argv += optind;

	do {
		if (argc > 0) { // argc が0でないなら
			if (freopen(argv[0], "r", stdin) == NULL) { // 標準入力をリセットして引数を開きなおす、nullなら
				perror(argv[0]); // 標準エラー出力
				exit(1); // 異常終了
			}
			argc--, argv++; // 引数の数を減らし、配列アドレスを進める。
		}
		column = 0;
		while ((c = getchar()) != EOF) { // EOF まで文字を読みこむ
			switch (c) { // 読みこんだ文字によって処理を分岐
			case '\t': // タブ文字
				if (nstops == 0) {
					do {
						putchar(' ');
						column++;
					} while (column & 07);
					continue; // 次の文字の処理
				}
				if (nstops == 1) {
					do {
						putchar(' ');
						column++;
					} while (((column - 1) % tabstops[0]) != (tabstops[0] - 1));
					continue;
				}
				for (n = 0; n < nstops; n++)
					if (tabstops[n] > column)
						break;
				if (n == nstops) {
					putchar(' ');
					column++;
					continue;
				}
				while (column < tabstops[n]) {
					putchar(' ');
					column++;
				}
				continue;

			case '\b': // バックスペース
				if (column)
					column--;
				putchar('\b');
				continue;

			default: // その他全ての文字
				putchar(c);
				column++;
				continue;

			case '\n':
				putchar(c);
				column = 0;
				continue;
			}
		}
	} while (argc > 0);
	exit(0);
}

static void
getstops(cp) // オプションの引数が渡される
	char *cp;
{
	int i;

	nstops = 0;
	for (;;) { // 無限ループ?
		i = 0;
		while (*cp >= '0' && *cp <= '9') // 1文字ずつ処理して文字列を数値に変換
			i = i * 10 + *cp++ - '0'; // i を10の位、1の位をcpの数値にする、そのあとインクリメント
		if (i <= 0 || i > 256) { // i が範囲外のとき実行
bad: //ラベル
			fprintf(stderr, "Bad tab stop spec\n"); // タブストップの大きさは256まで
			exit(1);
		}
		if (nstops > 0 && i <= tabstops[nstops-1])
			goto bad;
		tabstops[nstops++] = i;
		if (*cp == 0)
			break;
		if (*cp != ',' && *cp != ' ')
			goto bad;
		cp++;
	}
}

static void
usage()
{
	(void)fprintf (stderr, "usage: expand [-t tablist] [file ...]\n");
	exit(1);
}
