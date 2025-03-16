#include <iostream>
#include <vector>
using namespace std;

class MediaFile {
	
protected:
    string filePath;
    double size;
public:
    MediaFile(string path, double sz) : filePath(path), size(sz) {}

    virtual void play() {
        cout << "Playing media file " << filePath << endl;
    }

    virtual void stop() {
        cout << "Stopping media file " << filePath << endl;
    }

    virtual void displayInfo() {
        cout << "File Path " << filePath << "  Size " << size << "MB" << endl;
    }

    virtual ~MediaFile() {}
};

class VisualMedia : virtual public MediaFile {
protected:
    int resolutionX, resolutionY;
public:
    VisualMedia(string path, double sz, int resX, int resY) 
        : MediaFile(path, sz), resolutionX(resX), resolutionY(resY) {}

    void displayInfo() override {
        MediaFile::displayInfo();
        cout << "Resolution: " << resolutionX << "x" << resolutionY << endl;
    }
};

class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;
public:
    AudioMedia(string path, double sz, int rate) 
        : MediaFile(path, sz), sampleRate(rate) {}

    void displayInfo() override {
        MediaFile::displayInfo();
        cout << "Sample Rate: " << sampleRate << "Hz" << endl;
    }
};

class ImageFile : public VisualMedia {
public:
    ImageFile(string path, double sz, int resX, int resY)
        : MediaFile(path, sz), VisualMedia(path, sz, resX, resY) {}

    void play() override {
        cout << "Displaying image: " << filePath << endl;
    }
};

class AudioFile : public AudioMedia {
public:
    AudioFile(string path, double sz, int rate)
        : MediaFile(path, sz), AudioMedia(path, sz, rate) {}

    void play() override {
        cout << "Playing audio file: " << filePath << endl;
    }
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string path, double sz, int resX, int resY, int rate)
        : MediaFile(path, sz), VisualMedia(path, sz, resX, resY), AudioMedia(path, sz, rate) {}

    void play() override {
        cout << "Playing video: " << filePath << " | Resolution: " << resolutionX << "x" << resolutionY
             << " | Sample Rate: " << sampleRate << "Hz" << endl;
    }
};

int main() {
    ImageFile img("picture.jpg", 2.5, 1920, 1080);
    AudioFile audio("song.mp3", 5.0, 44100);
    VideoFile video("movie.mp4", 700, 1920, 1080, 48000);

    vector<MediaFile*> library = {&img, &audio, &video};

    cout << "--- Media Library ---" << endl;
    for (MediaFile* file : library) {
        file->displayInfo();
        file->play();
        file->stop();
        cout << "------------------" << endl;
    }

    return 0;
}
