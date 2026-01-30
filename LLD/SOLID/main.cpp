// Combined test harness to exercise all SOLID examples
#include <iostream>
#include <string>
using namespace std;

#include "D.cpp"
#include "I.cpp"
#include "L.cpp"
#include "O.cpp"
#include "S.cpp"

int main() {
    cout << "=== SOLID Principles Demo ===" << endl << endl;

    cout << "*** Single Responsibility (S) ***" << endl;
    demoS();

    cout << endl << "*** Liskov Substitution (L) ***" << endl;
    demoL();

    cout << endl << "*** Open/Closed (O) ***" << endl;
    demoO();

    cout << endl << "*** Dependency Inversion (D) ***" << endl;
    demoD();

    cout << endl << "*** Interface Segregation (I) ***" << endl;
    // Test ISP classes from I.cpp
    ModernAudioPlayer audioPlayer;
    audioPlayer.playAudio("song.mp3");
    audioPlayer.adjustAudioVolume(7);
    audioPlayer.stopAudio();

    SilentVideoPlayer videoPlayer;
    videoPlayer.playVideo("movie.mp4");
    videoPlayer.adjustVideoBrightness(50);
    videoPlayer.displaySubtitles("subs.srt");
    videoPlayer.stopVideo();

    ComprehensiveMediaPlayer mediaPlayer;
    mediaPlayer.playAudio("podcast.mp3");
    mediaPlayer.playVideo("clip.mp4");
    mediaPlayer.adjustAudioVolume(5);
    mediaPlayer.adjustVideoBrightness(75);
    mediaPlayer.displaySubtitles("allsubs.srt");
    mediaPlayer.stopAudio();
    mediaPlayer.stopVideo();

    cout << endl << "=== Demo complete ===" << endl;
    return 0;
}
