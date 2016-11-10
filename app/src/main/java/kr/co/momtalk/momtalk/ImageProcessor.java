package kr.co.momtalk.momtalk;
import org.opencv.*;
/**
 * 이미지를 이진화하는 클래스
 * Created by kimhy on 2016-11-08.
 */

public class ImageProcessor {
    private boolean[][] points;

    public ImageProcessor(int height,int width){
        points=new boolean[height][width];
    }

    public void parseimage() {

    }

    public boolean getpos(int x,int y){
        return points[x][y];
    }
}
