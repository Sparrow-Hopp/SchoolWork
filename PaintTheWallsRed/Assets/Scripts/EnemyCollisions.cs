using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class EnemyCollisions : MonoBehaviour
{
    void OnCollisionEnter2D(Collision2D col)
    {
        if (col.gameObject.tag == "Player")
        {
            Scene scene = SceneManager.GetActiveScene(); 
            SceneManager.LoadScene(scene.name);//reload current scene
        }
        else if (col.gameObject.tag == "Paint")
            gameObject.SetActive(false);
        else if (col.gameObject.tag == "StickyPaint")
            gameObject.SetActive(false);
        else if (col.gameObject.tag == "GhostPaint")
            gameObject.SetActive(false);
        else if (col.gameObject.tag == "RubberPaint")
            gameObject.SetActive(false);
    }
}
