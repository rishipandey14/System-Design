// ISP -> Interface Segregation Principle 

#include<iostream>
using namespace std;

class AudioPlayerControls {
public:
    virtual void playAudio(const string& audioFile) = 0;
    virtual void stopAudio() = 0;
    virtual void adjustAudioVolume(int volume) = 0;
    virtual ~AudioPlayerControls() = default;
};

class VideoPlayerControls {
public:
    virtual void playVideo(const string& videoFile) = 0;
    virtual void stopVideo() = 0;
    virtual void adjustVideoBrightness(int brightness) = 0;
    virtual void displaySubtitles(const string& subtitleFile) = 0;
    virtual ~VideoPlayerControls() = default;
};


class ModernAudioPlayer : public AudioPlayerControls {
public:
    void playAudio(const string& audioFile) override {
        cout << "ModernAudioPlayer: Playing audio - " << audioFile << endl;
    }
    
    void stopAudio() override {
        cout << "ModernAudioPlayer: Audio stopped. " << endl;
    }

    void adjustAudioVolume(int volume) override {
        cout << "ModernAudioPlayer: Volume set to " << volume << endl;
    }
};

class SilentVideoPlayer : public VideoPlayerControls {
public:
    void playVideo(const string& videoFile) override {
        cout << "SilentVideoPlayer: playing video - " << videoFile << endl;
    }
    void stopVideo() override {
        cout << "SilentVideoPlayer: Video stopped." << endl;
    }
    void adjustVideoBrightness(int brightness) override {
        cout << "SilentVideoPlayer: Brightness set to - " << brightness << endl;
    }
    void displaySubtitles(const string& subtitleFile) override {
        cout << "SilentVideoPlayer: Subtitles from - " << subtitleFile << endl;
    }
};

class ComprehensiveMediaPlayer : public AudioPlayerControls, public VideoPlayerControls {
public:
    void playAudio(const string& audioFile) override {
        cout << "ComprehensiveMediaPlayer: Playing audio - " << audioFile << endl;
    }
    
    void stopAudio() override {
        cout << "ComprehensiveMediaPlayer: Audio stopped. " << endl;
    }

    void adjustAudioVolume(int volume) override {
        cout << "ComprehensiveMediaPlayer: Volume set to " << volume << endl;
    }
    void playVideo(const string& videoFile) override {
        cout << "ComprehensiveMediaPlayer: playing video - " << videoFile << endl;
    }
    void stopVideo() override {
        cout << "ComprehensiveMediaPlayer: Video stopped." << endl;
    }
    void adjustVideoBrightness(int brightness) override {
        cout << "ComprehensiveMediaPlayer: Brightness set to - " << brightness << endl;
    }
    void displaySubtitles(const string& subtitleFile) override {
        cout << "ComprehensiveMediaPlayer: Subtitles from - " << subtitleFile << endl;
    }
};

