using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    [HideInInspector] //hides the following public variable (up to the statement terminator ";") in the Inspector
    public GameObject gridHolder;
    public Square squarePrefab; //assign in Inspector on Grid_Manager to Assets/Prefabs/Square
    public GameObject bounds;
    public float startX = 0;
    public float startY = 0;
    public float instX, instY;
    public int rows, cols;
    public static int numOfEnemyTypes = 4;
    public float wait, next;
    readonly float spacer = 0.05f; //readonly means what it says: spacer is not writable during runtime
    public GameObject [] enemy = new GameObject [numOfEnemyTypes];

    public Text nameTF; //Drag Grid_Name from Hierarchy to assign.
    public Text rowTF; //Drag Grid_Row from Hierarchy to assign.
    public Text colTF; //Drag Grid_Col from Hierarchy to assign.

    // GridManager will appear to be a public static class.
    private static GameManager instance;

    public GameObject player;

    public Text timerText;
    private float startTime;
    public string sceneName;
    int timer;
    static int timeElapsed;
    
    void InitGridHolder()
    {
        gridHolder = new GameObject();
        gridHolder.name = "Grid_Holder";
        gridHolder.transform.position = new Vector2(startX, startY);
    }

    void BuildGrid()
    {
        int tempi = 0, tempj = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                Square square = Instantiate(squarePrefab, gridHolder.transform);
                Vector2 newPos = new Vector2(j + (spacer * j), i + (spacer * i));
                square.transform.localPosition = newPos;
                square.name = "Square_" + i + "_" + j;
                square.gridPosition = new Vector2Int(i, j);
                Square.setCanMoveTo(square, moveable(i, j));
                Square.setCorner(square, isCorner(i, j));
                tempj = j + 1;
            }
            tempi = i + 1;
        }
        int c = -1;
        int r;
        for (r = -1; r <= tempi; r++)
        {
            GameObject squareBound = Instantiate(bounds, gridHolder.transform);
            Vector2 newPos = new Vector2(c + (spacer * c), r + (spacer * r));
            squareBound.transform.localPosition = newPos;
            squareBound.name = "Bound_" + r + "_" + c;
        }
        r = -1;
        c = -1;
        for (c = 0; c < tempj; c++)
        {
            do
            {
                GameObject squareBound = Instantiate(bounds, gridHolder.transform);
                Vector2 newPos = new Vector2(c + (spacer * c), r + (spacer * r));
                squareBound.transform.localPosition = newPos;
                squareBound.name = "Bound_" + r + "_" + c;
                r = r * -1 + tempi - 1;
            }while (r != -1);
        }
        for (r = -1; r <= tempi; r++)
        {
            GameObject squareBound = Instantiate(bounds, gridHolder.transform);
            Vector2 newPos = new Vector2(c + (spacer * c), r + (spacer * r));
            squareBound.transform.localPosition = newPos;
            squareBound.name = "Bound_" + r + "_" + c;
        }
    }

    void Start()
    {
        // squarePrefab = Resources.Load<Square>("Prefabs/Square");
        // avoid using Resources if you want to build the project see:
        // https://unity3d.com/learn/tutorials/topics/best-practices/resources-folder
        
        InitGridHolder();
        BuildGrid();
        instance = this; //the key to creating a singleton
        startTime = Time.time; 
        timeElapsed = 50;
    }

    public static void UpdateUI(Square square = null)
    {
        if (square == null)
        {
            instance.nameTF.text = "---";
            instance.rowTF.text = "---";
            instance.colTF.text = "---";
            return;
        }

        instance.nameTF.text = square.name;
        instance.colTF.text = square.gridPosition.x.ToString();
        instance.rowTF.text = square.gridPosition.y.ToString();
    }

    void Update()
    {
        if (Time.time > next)
        {
            GameObject enemySpawn = enemy[Random.Range(0, numOfEnemyTypes)];
            Vector2 spawnPos = new Vector2(instX, instY);
            next = Time.time + wait;//increasing the time until next spawn by however much the wait time is
            Instantiate(enemySpawn, spawnPos, Quaternion.identity);//instantiate a new enemy
        }
        float t = Time.time - startTime;

        int seconds = (int)t;

        timer = timeElapsed - seconds;

        timerText.text = timer.ToString();

        if (timer <= 0)
            SceneManager.LoadScene (sceneName);
    }

    public static void OnDown(Square square)
    {
        //instance.player.GetComponent<Player>().MovePlayer(square);
        if (Square.getCanMoveTo(square) == false);
        else
        {
            instance.player.GetComponent<Player>().LerpPlayer(square);
        }
    }

    public static void addTime(int add)//adds time to the timer
    {
        timeElapsed += add;
    }

    bool isCorner(int i, int j)
    {
        return ((i == 0 || i == rows - 1) && (j == 0 || j == cols - 1));//if the square is a corner
    }

    bool moveable(int i, int j)
    {
        return ((i == 0 || i == rows - 1 || i == rows / 2) && (j == 0 || j == cols - 1 || j == cols / 2));//if you can move to the square
    }
}