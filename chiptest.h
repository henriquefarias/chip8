/*  Test functions */

void screen_test(void)
{
    int line, column;

    /* Draw screen boundaries.  */
    SCREEN_BUFFER[0][0] = TRUE;
    SCREEN_BUFFER[0][63] = TRUE;
    SCREEN_BUFFER[31][0] = TRUE;
    SCREEN_BUFFER[31][63] = TRUE;
    draw_screen();
    getch();

    /* Fills the first line. */
    clear_screen();
    for (column = 0; column < SCREEN_W; column++)
        SCREEN_BUFFER[0][column] = TRUE;
    draw_screen();
    getch();

    /* Fills the entire screen. */
    clear_screen();
    for (line = 0; line < SCREEN_H; line++)
    {
        for (column = 0; column < SCREEN_W; column++)
            SCREEN_BUFFER[line][column] = TRUE;
    }
    draw_screen();
    getch();
}
