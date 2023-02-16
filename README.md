# 42 project - pipex
> Status: finished. 125/125

The purpose of this project is the discovery in detail UNIX mechanism - `pipe`.

## Implementation
Clone repository and type
```bash
$> make
```

## Description
Program needs to handle multiple pipes
```bash
$> < file1 cmd1 | cmd2 | cmd3 | ... | cmdn > file2

$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
Support `<<` and `>>`, when instead of `file1` is`here_doc`.
```bash
$> cmd1 << LIMITER | cmd2 >> file2

$> ./pipex here_doc LIMITER cmd1 cmd2 file2
```
The program handles almost all logical errors. 


## Salsa lessons

1. `Learn the basic steps:` Start by learning the basic steps of salsa, which involve a side-to-side movement and a forward-and-backward movement. In salsa, you step on beats 1, 2, and 3 of the music, and then pause on beat 4.
2. `Master the timing:` Salsa is danced to a specific rhythm, and it's important to get the timing right. The basic step is counted as "1-2-3, pause, 5-6-7, pause." Try counting the beats out loud as you dance to help you stay on rhythm.
3. `Practice partner work:` Salsa is typically danced with a partner, so it's important to learn how to lead or follow. Start with basic partner work, such as the cross-body lead or the right turn, and work your way up to more complex moves.
4. `Keep your posture and frame:` Good posture and a strong frame are essential for salsa dancing. Keep your head up, shoulders back, and chest out. Maintain a slight tension in your arms to help you stay connected to your partner.
5. `Add styling:` Once you feel comfortable with the basic steps and partner work, you can start to add your own style to the dance. This might involve adding body movement, footwork variations, or arm styling.
6. `Practice, practice, practice:` Salsa dancing takes practice, so don't get discouraged if you don't get it right away. Keep practicing the basic steps and partner work, and eventually, you'll be able to add more complex moves and styling to your dance.

> Keep in mind that the best way to learn how to dance salsa is to take classes with a qualified instructor. They can provide personalized feedback and help you improve your technique and style.
