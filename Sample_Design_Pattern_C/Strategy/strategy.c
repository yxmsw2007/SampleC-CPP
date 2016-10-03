typedef struct _MoviePlay
{
    struct _CommMoviePlay* pCommMoviePlay;
}MoviePlay;

typedef struct _CommMoviePlay
{
    HANDLE hFile;
    void (*play)(HANDLE hFile);
}CommMoviePlay;

void play_movie_file(struct MoviePlay* pMoviePlay)
{
    CommMoviePlay* pCommMoviePlay;
    assert(NULL != pMoviePlay);
    pCommMoviePlay = pMoviePlay->pCommMoviePlay;
    pCommMoviePLay->play(pCommMoviePlay->hFile);
}

void play_avi_file(HANDLE hFile)
{
    printf("play avi file!\n");
}

void play_rmvb_file(HANDLE hFile)
{
    printf("play rmvb file!\n");
}

void play_mpeg_file(HANDLE hFile)
{
    printf("play mpeg file!\n");
}
