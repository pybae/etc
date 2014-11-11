require 'ruby-processing'

class ProcessArtist < Processing::App

  def setup
    background(0, 0, 0)
    smooth
  end

  def draw 
  end

  def run_command(input)
    command = input[0]
    input = input[1..-1]

    case command
      when 'b'
        colors = input.split(",").collect{ |x| x.to_i }
        background(*colors)
      when 'q'
        abort "Program terminating"
    end
  end

  def mouse_pressed
    @draw = true
  end

  def mouse_released
    @draw = false
  end

  def mouse_dragged
    fill 255, 102, 18
    ellipse mouse_x, mouse_y, 10, 10
  end

  def key_pressed
    warn "A key was pressed! #{key.inspect}"
    @queue ||= ""

    if key != "\n"
      @queue << key
    else
      run_command(@queue)
      @queue = ""
    end

  end
end

ProcessArtist.new(:width => 800, :height => 800,
                  :title => "ProcessArtist", :full_screen => false)
